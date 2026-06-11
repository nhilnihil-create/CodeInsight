#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<int> arr,v;
int nxt[200005];
int last[200005];
int memo[200005];
int MOD=1000000007;
int main(){
    scanf("%d",&n);
    int t;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        arr.push_back(t);
    }
    v.push_back(arr[0]);
    for (int x=1;x<n;x++){
        if (v.back()!=arr[x]) v.push_back(arr[x]);
    }

    n=v.size();
    memset(nxt,-1,sizeof(nxt));
    memset(last,-1,sizeof(last));

    for (int x=0;x<n;x++){
        if (last[v[x]]!=-1) nxt[last[v[x]]]=x;
        last[v[x]]=x;
    }

    //for (int x=0;x<n;x++) printf("%d ",nxt[x]);

    memo[0]=1;
    for (int x=0;x<n;x++){
        if (nxt[x]!=-1) memo[nxt[x]]=memo[x];
        memo[x+1]=(memo[x+1]+memo[x])%MOD;
    }

    printf("%d\n",memo[n-1]);
}

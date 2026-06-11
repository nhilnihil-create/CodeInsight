#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> al[200005];
int w[200005];
void dfs(int i,int p){
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (*it==p) continue;
        w[*it]=w[i]+1;
        dfs(*it,i);
    }
}
int main(){
    scanf("%d",&n);
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }

    w[1]=0;
    dfs(1,-1);

    int best=1;

    for (int x=1;x<=n;x++){
        if (w[best]<w[x]) best=x;
    }

    w[best]=0;
    dfs(best,-1);

    int diam=0;
    for (int x=1;x<=n;x++) diam=max(diam,w[x]);

    printf((diam-1)%3?"First":"Second");
}

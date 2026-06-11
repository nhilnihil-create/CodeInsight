#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 
int n,m;
vector<int> g[100010];
int num[100010];
int par[100010];
 
int main(void){
    cin>>n>>m;
    for(int i=0;i<n+m-1;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        num[y]++;
    }
    queue<int>qu;
    for(int i=0;i<n;i++){
        if(num[i]==0)qu.push(i);
        par[i]=-1;
    }
    while(qu.size()>0){
        int now=qu.front();
        qu.pop();
        for(int i=0;i<(int)g[now].size();i++){
            int next=g[now][i];
            num[next]--;
            if(num[next]==0){
                par[next]=now;
                qu.push(next);
            }
        }
    }
    for(int i=0;i<n;i++)cout<<par[i]+1<<endl;
    return 0;
}
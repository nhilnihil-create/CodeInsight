#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 
vector<ll>g[10010];
bool visited[10010];
int main(void){
    ll n;
    cin>>n;
    vector<ll>c(n),ans(n);
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll m = 0;
    for(ll i=0;i<n;i++){
        cin>>c[i];
        m+=c[i];
    }
    sort(c.begin(),c.end(),greater<ll>());
    cout<<m-c[0]<<endl;
    ans[0]=c[0];
    queue<ll>que;
    ll index = 1;
    que.push(0);
    visited[0]=true;
    while(!que.empty()){
        ll now = que.front();
        que.pop();
        for(ll i=0;i<g[now].size();i++){
            ll next = g[now][i];
            if(visited[next])continue;
            ans[next]=c[index];
            index++;
            visited[next]=true;
            que.push(next);
        }
    }
    for(int i=0;i<n;i++){
        if(i==n-1)cout<<ans[i]<<endl;
        else cout<<ans[i]<<" ";
    }
    return 0;
}
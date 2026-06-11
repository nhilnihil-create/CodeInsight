#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()

using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int n,m; cin >> n >> m;
    vector<int> G[n];
    rep(i,m){
        int x,y,z; cin >> x >> y >> z;
        x--; y--;
        G[x].pb(y);
        G[y].pb(x);

    }
    int ans=0;
    queue<int> q;
    vector<bool> vis(n,0);
    rep(i,n){
        if(!vis[i]){
            q.push(i); vis[i]=1;
            while(!q.empty()){
                int v=q.front(); q.pop();
                for(int u:G[v]){
                    if(vis[u]) continue;
                    vis[u]=1; q.push(u);
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
}

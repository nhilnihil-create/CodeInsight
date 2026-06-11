#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

bool visited[100010] = {};
struct choten{
    ll pnt = -1;
    ll ance = 0;
    vector<ll> chld;
};
choten c[100010];

void dfs(ll x, ll y){
    c[x].pnt = y;
    visited[x] = true;
    rep(i, c[x].chld.size())c[c[x].chld[i]].ance--;
    rep(i, c[x].chld.size())if(c[c[x].chld[i]].ance==0&&!visited[c[x].chld[i]])dfs(c[x].chld[i], x);
}

int main(){
   ll n, m;
   cin >> n >> m;
   rep(i, n+m-1){
       ll a, b;
       cin >> a >> b;
       c[a].chld.push_back(b);
       c[b].ance++;
   }
   ll bigdaddy;
   rep(i, n)if(c[i+1].ance == 0){
       bigdaddy = i+1;
       break;
   }
   dfs(bigdaddy, 0);
   rep(i, n)cout << c[i+1].pnt << endl;
}
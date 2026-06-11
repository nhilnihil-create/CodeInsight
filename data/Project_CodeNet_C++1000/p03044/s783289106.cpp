#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
ll n;
vector<vector<pair<ll,ll>>> g;

int check[110000];

void dfs(int now,int c){
  if(check[now]!=-1)return;
  check[now]=c;
  for(auto v:g[now]){
   int next=v.first;
   int flag=v.second;
    dfs(next,(flag+c)%2);
  }
  return;
}

int main(){cout<<fixed<<setprecision(20);
		   //dfs
           cin>>n;
           g.resize(n,vector<pair<ll,ll>>());
           ll a,b,c;
           rep(i,0,n-1){
             cin>>a>>b>>c;
             a--;b--;c%=2;
             g[a].pb(mp(b,c));
             g[b].pb(mp(a,c));
           }
           rep(i,0,n)check[i]=-1;
           dfs(0,0);
           rep(i,0,n){
            cout<<check[i]<<endl; 
           }
}
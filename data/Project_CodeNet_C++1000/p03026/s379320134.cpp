#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
  

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n;
  cin >> n;
  vvl G(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  priority_queue<ll>c;
  rep(i,n){
    ll x;
    cin >> x;
    c.push(x);
  }
  vector<ll>ans(n,-1);
  queue<int>q;
  q.push(0);
  ans[0]=c.top();
  c.pop();
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int nv:G[v]){
      if(ans[nv]!=-1)continue;
      ans[nv]=c.top();
      c.pop();
      q.push(nv);
    }
  }
  ll sum=0;
  rep(i,n)sum+=ans[i];
  cout << sum-*max_element(all(ans)) << endl;
  rep(i,n){
    if(i!=0)cout << " ";
    cout << ans[i];
  }
  
}

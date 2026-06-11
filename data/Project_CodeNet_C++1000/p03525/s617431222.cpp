#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
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
  vector<int> pos(24);
  pos[0]++;
  
  map<int, int> mp;
  rep(i, n){ 
    int d;
    cin >> d;
    if(d>=13) d = 24-d;
    mp[d]++;
  }
  
  bool ok = true;
  
  int lr=0;
  for(auto p : mp){
    if(p.second >= 3) ok = false;
    if(p.first == 0) ok = false;
    if(p.first == 12 && p.second >=2) ok = false;
    
    if(p.second == 1){
      if(lr == 0){
        pos[p.first]++;
        lr = 1;
      }else{
        pos[24-p.first]++;
        lr = 0;
      }
    }
    if(p.second == 2){
      pos[p.first]++;
      pos[24-p.first]++;
    }
  }
  
  int ans = 13;
  rep(i, 24){
    rep(j, 24){
      if(i == j) continue;
      if(pos[i] && pos[j]){
        int gap = abs(i-j);
        chmin(ans ,min(gap,24-gap));
      }
    }
  }
  
  if(ok) cout << ans << endl;
  else cout << 0 << endl;
    
  return 0;     
}

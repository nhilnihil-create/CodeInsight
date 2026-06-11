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
  
  ll n,m;
  cin >> n >> m;
  vector<P>vec(m+1);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    vec[i]=P(b,a);
  }
  vec[m]=P(INF,INF);
  sort(vec.begin(),vec.end());
  ll cnt=0;
  ll now=0;
  rep(i,m){
    if(now<=vec[i].second){
      cnt++;
      now=vec[i].first;
    }
  }
  cout << min(cnt,n-1) << endl;
        
  return 0;     
}

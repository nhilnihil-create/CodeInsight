#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}

/*Coding Space*/
int main(){
  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  int ans = 0;
  rep(i,30){
    vi c(n);
    rep(j,n) c[j] = a[j]&((1<<(i+1))-1);
    sort(ALL(c));
    rep(x,n){
      int t = b[x] &((1<<(i+1))-1);
      int cnt = lower_bound(ALL(c),pow(2,i+1,LLINF) - t) - lower_bound(ALL(c),pow(2,i,LLINF) - t);
      cnt += lower_bound(ALL(c), pow(2,i+3,LLINF) - t) - lower_bound(ALL(c),3 * pow(2,i,LLINF) - t);
      if(cnt%2)  ans ^= (1 << i);
    }
  }
  cout << ans << endl;
}

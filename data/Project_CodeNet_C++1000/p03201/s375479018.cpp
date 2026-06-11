#include <bits/stdc++.h>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef vector< vector< vector<ll> > > vvvint;
typedef vector<string> vstring;
typedef vector< vector<string> > vvstring;
typedef vector<char> vchar;
typedef vector< vector<char> > vvchar;
typedef vector<long double> vdouble;
typedef vector< vector<long double> > vvdouble;
typedef vector< vector< vector<long double> > > vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ALL(obj) (obj).begin(), (obj).end()
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define MOD 1000000007
const double PI=3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int msb(ll n){
  int ret = -1;

  while(n > 0){
    n>>=1;
    ret++;
  }


  return ret;
}


int main() {


  cout<<fixed<<setprecision(10);
  ll n;
  cin>>n;
  vint a(n);
  rep(i,n) cin>>a[i];
  sort(ALL(a));
  map<ll,ll> cnt;
  rep(i,n) cnt[a[i]]++;
  set<ll> used; // used indices
  ll ans = 0;


  for(ll i=n-1; i>=0; i--){
    // if(used.count(i)) continue;
    if(cnt[a[i]] == 0) continue;
    // cout<<a[i]<<endl;
    cnt[a[i]]--;
    if(a[i]&(a[i]-1) == 0){// 2べき
      if(cnt[a[i]] > 0){
        ans++;
        cnt[a[i]]--;
      }
    }else{
      ll t = (1<<(1+msb(a[i]))) - a[i];
      if(cnt[t]>0){
        ans++;
        cnt[t]--;
      }
    }

  }

  cout<<ans<<endl;



}
//

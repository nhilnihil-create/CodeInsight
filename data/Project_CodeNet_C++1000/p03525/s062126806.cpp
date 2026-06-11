#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI d(n);
  ll ans = 100;
  rep(i,n){
    cin >> d[i];
    ans = min<ll>(d[i],ans);
  }
  sort(all(d));

  VI r, l;
  rep(i,n){
    if(d[i] == 12){
      l.push_back(d[i]);
      r.push_back(d[i]);
      continue;
    }

    if(i % 2 == 0){
      r.push_back(d[i]);
    }else{
      l.push_back(d[i]);
    }
  }

  rep(i,(int)r.size() - 1) ans = min<ll>(r[i+1] - r[i], ans);
  rep(i,(int)l.size() - 1) ans = min<ll>(l[i+1] - l[i], ans);
  if(r.back() != 12){
    if(r.size() >= 1 && l.size() >= 1)ans = min<ll>(ans,24-r.back()-l.back());
  }

  cout << ans << endl;
  return  0;
}

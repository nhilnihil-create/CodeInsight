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


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

ll dp[2][101010];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,c;
  cin >> n >>  c;
  VLL x(n), v(n);
  rep(i,n){
    cin >> x[i] >> v[i];
  }

  /*
    本当は、時計回り側が長くなる最大の距離の地点と、
    反時計回りが長くなる時の最大値を比較するだけでよい。
    どうしよう.....
    右側の回った時の最大値と
    左から回った時の最大値を計算
  */
  ll ans = 0;

  VLL maxLeft(n,0);
  ll cal = 0;
  rep(i,n){
    if(i != 0) cal += -x[i] + x[i-1];
    else cal -= x[i];
    cal += v[i];
    if(i != 0) maxLeft[i] = max(maxLeft[i-1],cal);
    else maxLeft[i] = max(0LL,cal);
    ans = max(maxLeft[i],ans);
  }
  //cout << ans << endl;
  cal = 0;
  VLL maxRight(n,0);
  for(ll i = n-1; i >= 0; i --){
    if(i != n-1) cal += x[i] - x[i+1];
    else cal -= c - x[i];
    cal += v[i];
    if(i != n-1) maxRight[i] = max(maxRight[i+1],cal);
    else maxRight[i] = max(0LL,cal);
    ans = max(maxRight[i],ans);
  }
  //cout << ans << endl;


  rep(i,n-1){
    ans = max(ans,maxLeft[i] + maxRight[i+1] - x[i]);
    ans = max(ans, maxLeft[i] + maxRight[i+1] - c + x[i+1]);
  }

  cout << ans << endl;

    return 0;
}

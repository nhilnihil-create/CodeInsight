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
  string s;
  cin >> s;

  vector<int> dd;
  vector<int> cc;
  vector<int> mm;

  rep(i,n){
    if(s[i] == 'D') dd.push_back(i);
    if(s[i] == 'M') mm.push_back(i);
    if(s[i] == 'C') cc.push_back(i);
  }

  ll mSum[n];
  memset(mSum,0,sizeof(mSum));
  if(s[0] == 'M') mSum[0]++;
  FOR(i,1,n){
    if(s[i] == 'M') mSum[i] = mSum[i-1] + 1;
    else mSum[i] = mSum[i-1];
  }

  ll cSum[n];
  memset(cSum,0,sizeof(cSum));
  rep(i,n){
    if(s[i] == 'C') cSum[i] ++;
    if(i-1 >= 0) cSum[i] += cSum[i-1];
  }

  ll mcSum[n];
  memset(mcSum,0,sizeof(mcSum));
  rep(i,n){
    if(s[i] == 'C') mcSum[i] = mSum[i];
  }

  FOR(i,1,n){
    mcSum[i] += mcSum[i-1];
  }

  int q;
  cin >> q;
  rep(_,q){
    int k;
    cin >> k;
    ll ans = 0;
    for(int l: dd){
      auto itrR = lower_bound(all(cc), l+k);
      if(itrR == cc.begin()){
        continue;
      }
      int r = *(itrR - 1);
      ll ccnt = cSum[r];
      if(l - 1 >= 0) ccnt -= cSum[l-1];
      ans += mcSum[r] - mcSum[l] - ccnt * mSum[l];
    }
    cout << ans << endl;
  }
  return 0;
}

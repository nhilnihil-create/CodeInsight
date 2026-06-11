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
  string s;
  cin >> s;
  if(s[0] == '0'){
    cout << -1 << endl;
    return 0;
  }

  if(s.back() == '1'){
    cout << -1 << endl;
    return 0;
  }
  ll n = s.size();
  rep(i,n-1){
    if(s[i] != s[n-2-i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  int nodeCnt = 1;
  cout << nodeCnt << " " << nodeCnt+1 << endl;
  nodeCnt++;
  FOR(i,1,s.size()) {
    if(s[i] == '0') continue;
    int pathNode = nodeCnt;
    nodeCnt++;
    while(nodeCnt <= i+1){
      cout << pathNode << " " << nodeCnt << endl;
      nodeCnt++;
    }
    if(nodeCnt <= s.size()) cout << pathNode << " " << nodeCnt << endl;
  }
  return 0;
}

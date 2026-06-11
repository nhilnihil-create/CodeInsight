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
  int n, k;
  cin >> n >> k;
  VI t(210101,0);
  VI s(n),e(n),c(n);
  vector<PII> ch[k];
  rep(i,n){
    cin >> s[i] >> e[i] >> c[i];
    c[i]--;
    ch[c[i]].push_back(PII(s[i],e[i]));
  }

  rep(i,k){

    if(ch[k].size() == 0) continue;

    sort(all(ch[i]));
    rep(j,(int)ch[i].size() - 1){
      if(ch[i][j].second == ch[i][j+1].first){
        ch[i][j+1].first = ch[i][j].first;
        ch[i][j].first = -1;
      }
    }

    rep(j,ch[i].size()){
      if(ch[i][j].first == -1) continue;
      else {
        // cout << i << " " << ch[i][j].first << "," << ch[i][j].second << endl;
        t[2*ch[i][j].first - 1]++;
        t[2*ch[i][j].second + 1]--;
      }
    }
  }

  int cnt = 0;
  rep(i,210100){
    t[i+1] += t[i];
    cnt = max(t[i],cnt);
  }
  cout << cnt << endl;
  return 0;
}

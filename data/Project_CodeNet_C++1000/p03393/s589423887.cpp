#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

// const value
// const ll MOD = 1e9 + 7;
// const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
// const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline ll toLL(string s) {
  ll v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  if(n < 26) {
    bool alpha[26] = {0};
    rep(i, n) alpha[(s[i] - 'a')] = true;
    rep(i, 26) {
      if(alpha[i] == false) {
        cout << s << (char)('a' + i) << endl;
        return 0;
      }
    }
  }
  vector<string> ans;
  for(int i = n - 1; i >= 0; i--) {
    for(int j = i - 1; j >= 0; j--) {
      if(s[i] > s[j]) {
        swap(s[i], s[j]);
        ans.push_back(s.substr(0, j + 1));
        swap(s[i], s[j]);
      }
    }
  }
  if(ans.size() == 0) {
    cout << -1 << "\n";
  } else {
    sort(all(ans));
    cout << ans[0] << endl;
  }

  return 0;
}

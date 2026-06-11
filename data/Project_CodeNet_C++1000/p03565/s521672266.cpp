#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S,T;
  cin >> S >> T;

  if (S.size() < T.size()) {
    cout << "UNRESTORABLE"<< endl;
    return 0;
  }

  string ans;

  for (int i = 0; i <= S.size() - T.size(); ++i) {
    string s = S;
    bool flag = true;
    for (int j = 0; j < T.size(); ++j) {
      if (S[i+j] != '?' && S[i+j] != T[j]) {
        flag = false;
        break;
      }
      s[i+j] = T[j];
    }

    if (flag) {
      for (int j = 0; j < s.size(); ++j) {
        if (s[j] == '?') s[j] = 'a';
      }
      if (ans.empty()) ans = s;
      chmin(ans, s);
    }
  }

  if (ans.empty())
    cout << "UNRESTORABLE" << endl;
  else
    cout << ans << endl;
}
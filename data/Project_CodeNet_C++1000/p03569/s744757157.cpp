#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

bool is_palindrome(string S) {
  rep(i, S.size()) {
    if (S[i] != S[S.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string S; cin >> S;
  string T;
  rep(i, S.size()) {
    if (S[i] != 'x') {
      T.push_back(S[i]);
    }
  }
  if (!is_palindrome(T)) {
    cout << "-1\n";
  }
  else {
    int N = S.size();
    int right = N - 1;
    int l_xcnt = 0, r_xcnt = 0, ans = 0;
    rep(left, N) {
      if (S[left] != 'x') {
        while (right && S[right] == 'x') right--, r_xcnt++;
        ans += abs(l_xcnt - r_xcnt);
        l_xcnt = r_xcnt = 0;
        right--;
      }
      else {
        l_xcnt++;
      }
      if (left >= right) {
        break;
      }
    }
    cout << ans << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int find_all(string str, string subStr) {
  int result = 0;
  int subStrSize = subStr.size();
  int pos = str.find(subStr);

  while (pos != std::string::npos) {
    result++;
    pos = str.find(subStr, pos + subStrSize);
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  int a_count = 0;
  int b_count = 0;
  int w_count = 0;
  int ab_count = 0;
  REP(i, n) {
    string s;
    cin >> s;
    ab_count += find_all(s, "AB");
    if (s[0] == 'B' && s[s.length() - 1] == 'A') {
      w_count++;
    } else if (s[0] == 'B') {
      b_count++;
    } else if (s[s.length() - 1] == 'A') {
      a_count++;
    }
  }
  while (a_count != 0 || b_count != 0) {
    if (a_count < b_count) {
      swap(a_count, b_count);
    }
    if (w_count > 0) {
      w_count--;
      ab_count++;
    } else if (a_count != 0 && b_count != 0) {
      a_count--;
      b_count--;
      ab_count++;
    } else {
      break;
    }
  }
  if (w_count > 0) ab_count += (w_count - 1);
  cout << ab_count << endl;
}
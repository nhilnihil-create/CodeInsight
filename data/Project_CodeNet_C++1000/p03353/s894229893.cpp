#include <iostream>
#include <string>

using namespace std;
#ifdef ONLINE_JUDGE
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');
#endif

inline int findstr(const string& s, const int& begin, const int& end, const string& t, const int& tl) {
  for (int i = begin; i <= end - tl;) {
    for (int j = 0; j < tl; ++j) {
      if (s[i + j] != t[j]) goto cont;
    }
    return i;
  cont:
    ++i;
  }
  return -1;
}
int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  string t(5, 0);
  for (char c = 'a'; c <= 'z'; ++c) {
    t[0] = c;
    int l0 = findstr(s, 0, n, t, 1);
    if (l0 < 0) continue;
    if (k == 1) {
      cout << t[0] << endl;
      return 0;
    }
    --k;
    for (char c = 'a'; c <= 'z'; ++c) {
      t[1] = c;
      int l1 = findstr(s, l0, n, t, 2);
      if (l1 < 0) continue;
      if (k == 1) {
        cout << t[0] << t[1] << endl;
        return 0;
      }
      --k;
      for (char c = 'a'; c <= 'z'; ++c) {
        t[2] = c;
        int l2 = findstr(s, l1, n, t, 3);
        if (l2 < 0) continue;
        if (k == 1) {
          cout << t[0] << t[1] << t[2] << endl;
          return 0;
        }
        --k;
        for (char c = 'a'; c <= 'z'; ++c) {
          t[3] = c;
          int l3 = findstr(s, l2, n, t, 4);
          if (l3 < 0) continue;
          if (k == 1) {
            cout << t[0] << t[1] << t[2] << t[3] << endl;
            return 0;
          }
          --k;
          for (char c = 'a'; c <= 'z'; ++c) {
            t[4] = c;
            int l4 = findstr(s, l3, n, t, 5);
            if (l4 < 0) continue;
            if (k == 1) {
              cout << t[0] << t[1] << t[2] << t[3] << t[4] << endl;
              return 0;
            }
            --k;
          }
        }
      }
    }
  }
}

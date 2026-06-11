#include<bits/stdc++.h>

#define fi first
#define se second
#define show(x) cerr << #x << "=" << "\n"
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;
int a[30];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  FILE *stream1;
  //FILE *stream2;
  stream1 = freopen("in.txt", "r", stdin);
  //stream2 = freopen("out.txt", "w", stdout);
  if (stream1 == NULL) return 0;
  //if (stream2 == NULL) return 0;:w
#endif
  cin >> s;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  string t = "";
  while (true) {
    bool zero = 1;
    for (int i = 0; i < 26; i++) {
      if (a[i] > 0) {
        t += (char)('a' + i);
        a[i]--;
        zero = 0;
      }
    }
    if (zero) {
      break;
    }
  }
  int now = 1;
  char pre = t[0];
  int m = (int)t.size();
  for (int i = 1; i < m; i++) {
    if (pre >= t[i]) {
      if (now > 2) {
        now = 1;
        pre = t[i];
      } else {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      now++;
      pre = t[i];
    }
  }
  cout << "YES" << endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
  fclose(stream1);
  //fclose(stream2);
#endif
  return 0;
}
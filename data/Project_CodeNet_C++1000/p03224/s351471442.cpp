#include<bits/stdc++.h>

#define fi first
#define se second
#define show(x) cerr << #x << "=" << "\n"
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
int a[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  FILE *stream1;
  FILE *stream2;
  stream1 = freopen("in.txt", "r", stdin);
  stream2 = freopen("out.txt", "w", stdout);
  if (stream1 == NULL) return 0;
  if (stream2 == NULL) return 0;
#endif
  cin >> n;
  int ii;
  for (ii = 1; ii * (ii + 1) / 2 < n; ii++) {}
  if (ii * (ii + 1) / 2 == n) {
    cout << "Yes" << endl;
    int now = 1;
    for (int i = 0; i < ii; i++) {
      for (int j = 0; j <= i; j++) {
        a[i][j] = now;
        now++;
      }
    }
    cout << ii + 1 << endl;
    for (int cor = 0; cor < ii; cor++) {
      cout << ii << " ";
      for (int j = 0; j < cor; j++) {
        cout << a[cor][j] << " ";
      }
      for (int j = cor; j < ii; j++) {
        cout << a[j][cor] << " ";
      }
      cout << endl;
    }
    cout << ii << " ";
    for (int i = 1; i <= ii; i++) {
      cout << i * (i + 1) / 2 << " ";
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
  fclose(stream1);
  fclose(stream2);
#endif
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> x(N), y(N), h(N);
  for (long i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }

  long ansx = 0, ansy = 0;
  long tmp = -1;
  for (long cx = 0; cx < 101; cx++) {
    for (long cy = 0; cy < 101; cy++) {
      for (long i = 0; i < N; i++) {
        if (tmp == -1 && h[i] > 0) {
          tmp = abs(x[i]-cx)+abs(y[i]-cy)+h[i];
          goto next;
        }
      }
next:
      for (long i = 0; i < N; i++) {
        long h1 = tmp-abs(x[i]-cx)-abs(y[i]-cy);
        long h2 = h1 > 0 ? h1 : 0;
        if (h[i] != h2) goto out;
      }
      ansx = cx;
      ansy = cy;
      goto end;
out:
      tmp = -1;
      ansx = -1;
      ansy = -1;
    }
  }
end:
  cout << ansx << " " << ansy << " " << tmp << endl;
  return 0;
}
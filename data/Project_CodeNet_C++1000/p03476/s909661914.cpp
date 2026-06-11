#include <bits/stdc++.h>
using namespace std;

bool v[100100];
int p[100100];

bool is_prime(long N) {
  for (long i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      return false;
    }
  }
  return N != 1;
}

int main() {

  for (int i = 1; i < 100100; i++) {
    v[i] = is_prime(i);
  }

  p[0] = 0;
  p[1] = 0;
  p[2] = 0;

  for (int i = 3; i < 100100; i++) {
    if (i % 2 != 0) {
      if (v[(i + 1) / 2] && v[i]) {
        p[i] = p[i - 1] + 1;
      } else {
        p[i] = p[i - 1];
      }
    } else {
      p[i] = p[i - 1];
    }
  }

  int Q;
  cin >> Q;

  vector<pair<int,int>> lr;

  while (0 < Q) {

    int l, r;
    cin >> l >> r;

    lr.push_back(make_pair(l,r));

    Q--;
  }

  for (int i = 0; i < lr.size(); i++) {

    int l_ = lr[i].first;
    int r_ = lr[i].second;

    cout << p[r_] - p[l_ - 1] << endl;
  }

}
#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 100000;
const int MIN_A = -100000;
const int RANGE = MAX_A - MIN_A + 1;
const int BIAS = -MIN_A;
int n;
vector<int> l, r;
int lc[RANGE] = {}, rc[RANGE] = {};

int main()
{
  cin >> n;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    lc[x+BIAS]++, rc[y+BIAS]++;
  }
  lc[BIAS]++, rc[BIAS]++;

  for (int i = 0; i < RANGE; i++) {
    while (lc[RANGE-1-i]--) l.push_back(RANGE-1-BIAS-i);
    while (rc[i]--) r.push_back(i-BIAS);
  }

  uint64_t d = 0;
  for (int i = 0; i < n && l[i] > r[i]; i++)
    d += (l[i] - r[i]) * 2;

  cout << d << endl;

  return 0;
}

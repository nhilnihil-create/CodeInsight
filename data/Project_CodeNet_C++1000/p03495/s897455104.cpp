#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  const int N_MAX = 200001;
  int n, k, a[N_MAX];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int boll[N_MAX] = {0};
  for (int i = 0; i < n; i++) {
    boll[a[i] - 1]++;
  }
  sort(boll, boll + N_MAX);
  int notZero = 0;
  while (boll[notZero] == 0) notZero++;
  int kind = N_MAX - notZero;
  int res = 0;
  for (int i = 0; kind - i > k; i++) {
    res += boll[notZero + i];
  }
  cout << res << endl;
  return 0;
}
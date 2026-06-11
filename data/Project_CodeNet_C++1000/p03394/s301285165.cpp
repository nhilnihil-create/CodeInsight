#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int a[100];

int GCD(int a, int b) {
  if (a == 0) return b;
  return GCD(b % a, a);
}

bool Check(int n) {
  int g = a[0];
  for (int i = 0; i < n; ++i) g = GCD(g, a[i]);
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i] == a[j]) return false;
  if (g != 1) return false;
  int sum = accumulate(a, a + n, 0);
  for (int i = 0; i < n; ++i) {
    if (GCD(a[i], sum - a[i]) == 1) return false;
  }
  return true;
}

void Solve(int at, int n, int cap) {
  if (at == n && Check(n)) {
    for (int i = 0; i < n; ++i) {
      if (i) cout << " ";
      cout << a[i];
    }
    cout << endl;
    exit(0);
  }

  if (at == n) return;

  for (int i = 2; i <= cap; ++i) {
    a[at] = i;
    Solve(at + 1, n, cap);
  }
}

int main()
{
  vector<int> a;
  for (int i = 1; i < 30001; ++i) {
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) a.push_back(i);
  }
  int n;
  cin >> n;

  for (;;) {
    random_shuffle(a.begin(), a.end());
    int g = a[0];
    int sum = accumulate(a.begin(), a.begin() + n, 0);
//    for (int i = 0; i < n; ++i) {
//      printf("%d%d%d ", a[i] % 2, a[i] % 3, a[i] % 5);
//    }
//    cout << endl;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      g = GCD(g, a[i]);
      if (GCD(sum, a[i]) == 1) ok = false;
    }
    if (g != 1) continue;
    if (!ok) continue;
    for (int i = 0; i < n; ++i) {
      if (i) cout << " ";
      cout << a[i];
    }
    cout << endl;
    return 0;
  }

  return 0;


  Solve(0, n, 20);
  return 0;
  for (int i = 0; i < n - 2; ++i) cout << "2 ";
  cout << "3 ";
  if (n % 3 == 2) {
    cout << "3\n";
    return 0;
  }
  cout << (n - 1) * 10 + 5 << endl;
  return 0;
}

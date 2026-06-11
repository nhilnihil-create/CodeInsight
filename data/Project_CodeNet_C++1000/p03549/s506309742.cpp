#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int Pow(int a, int n) {
  if (n == 1) return a;
  if (n % 2 == 1) return (a * Pow(a, n-1));
  int t = Pow(a, n/2);
  return t*t;
}

int main() {
  int N, M;
  cin >> N >> M;
  int time = (N-M)*100+M*1900;
  int cnt = Pow(2, M);
  cout << time*cnt << endl;
}

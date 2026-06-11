#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(A * N, B) <<endl;
} 

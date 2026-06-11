#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> SE;
  int A, B, K;
  cin >> A >> B >> K;
  int a = A, b = B;
  for (int i = 0; i < K; i++) SE.insert(a++), SE.insert(b--);
  for (auto se : SE) if (se >= A && se <= B) cout << se << "\n";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  string answer = (((N+1) / 2) >= K ? "YES" : "NO");
  cout << answer << "\n";
}
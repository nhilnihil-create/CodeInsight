#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
      int b;
      cin >> b;
      a.at(i) = b;
  }
  int  ans = 0;
  for(int i = 0; i < N; i++){
      ans += a.at(i) - 1;
  }
  cout << ans << endl;
}
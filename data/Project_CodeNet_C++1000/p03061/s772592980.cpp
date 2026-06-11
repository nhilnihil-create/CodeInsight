#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N+2);
  for (int i = 1; i < N+1; i++) {
      cin >> a.at(i);
  }

  vector<int> data1(N+2);
  vector<int> data2(N+2);

  data1.at(0) = 0;
  data2.at(N+1) = 0;
  
  for (int i = 1; i < N+1; i++) {
      data1.at(i) = __gcd(a.at(i),data1.at(i-1));
  }

  for (int i = N; i >= 1; i--) {
      data2.at(i) = __gcd(a.at(i),data2.at(i+1));
  }

  int ans = 0;

  for (int i = 1; i <= N; i++) {
      int g = __gcd(data1.at(i-1),data2.at(i+1));
      ans = max(ans,g);
  }

  cout << ans << endl;

}

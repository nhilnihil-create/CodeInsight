#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> sum(n);
  long long ans = 0;
  for(int i = 0; i < n; i++){
    long long a, b;
    cin >> a >> b;
    ans -= b;
    sum.at(i) = a + b;
  }
  
  sort(sum.begin(), sum.end());
  reverse(sum.begin(), sum.end());
  for(int i = 0; i < n; i++){
    if(i % 2) continue;
    ans += sum.at(i);
  }
  
  cout << ans << endl;
}
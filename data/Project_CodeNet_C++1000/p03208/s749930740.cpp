#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k,n;
  long long Min = 9999999999;
  long long tmp;
  
  cin >> n >> k;
  vector<long long> vec(n);
  
  for(int i = 0; i < n; i++) cin >> vec.at(i);
  
  sort(vec.begin(), vec.end(),greater<int>());
  
  for(int i = 0; i < n - k + 1; i++){
    tmp = vec.at(i) - vec.at(k + i - 1);
    Min = min(tmp,Min);
  }
  
  cout << Min;
  
}

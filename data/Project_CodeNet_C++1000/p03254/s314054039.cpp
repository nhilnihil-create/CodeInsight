#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,x;
  cin >> N >> x;
  
  vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  
  int count = 0;
  long long sum = 0;
  
 if (a.at(0) > x){
   cout << 0 << endl;
 }
 else {
  for (int i = 0; i < N; i++) {
    sum += a.at(i);
    count++;
    if (x < sum){
      cout << count - 1 << endl;
      break;
    }
    else if (i == N - 1 && x == sum){
      cout << N << endl;
      break;
    }
    else if (i == N - 1 && x > sum){
      cout << N - 1 << endl;
      break;
    }
  }
 }
}    
  


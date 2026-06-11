#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, sum;
  int64_t x;
  cin >> N >> x;
  vector<int64_t> a(N);
  for (int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  for (int i = N; i > 0; i--){
    sum = 0;
    for (int j = 0; j < i; j++){
      sum += a.at(j);
    }
    if ((i < N && sum <= x )||(i == N && sum == x)){
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}

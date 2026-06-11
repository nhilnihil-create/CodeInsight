#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  
  int ans = 0, num = 0;
  for (int i = N - 1; i >= 0; i--){
    if (num % 2 == 0){
      ans += A.at(i);
    }
    else{
      ans -= A.at(i);
    }
    
    num++;
  }
  
  cout << ans << endl;
}
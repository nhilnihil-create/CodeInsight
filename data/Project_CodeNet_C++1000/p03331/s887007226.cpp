#include <bits/stdc++.h>
using namespace std;

int cal_sum_digits(int n){
  int sum = 0;
  while(n > 0){
    sum += ( n % 10);
    n /= 10;
  }
  return sum;
}

int main(){
  int N,ans = INT_MAX;
  cin >> N;
  for(int i = 1; i < N;i++){
    int a = i,b= N - i;
    ans = min(ans,cal_sum_digits(a) + cal_sum_digits(b));
  }
  cout << ans << endl;
}
    
  
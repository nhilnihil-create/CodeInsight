#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  long long N;
  cin >> N;
  long long ans;
  long long n = sqrt(N);
  rep(i,n+1){
    if(i*i <= N) ans = i;
  }
  cout << ans*ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  long long  ans=10000000000;
  long long  sum=0;
  long long  A;
  cin >> N ;
  for(int i = 0; i < N; i++){
    cin >> A;
    sum=0;
    while(A % 2 ==0) {
      sum++;
      A /= 2;
    }
    if (sum <= ans ) ans = sum;
  }
  cout << ans << endl;
}
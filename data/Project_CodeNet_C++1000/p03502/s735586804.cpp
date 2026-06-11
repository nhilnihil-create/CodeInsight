#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,tmp;
  cin >> N;
  int sum = 0;
  tmp = N;
  while(N){
    sum += N % 10;
    N = N / 10;
  }
//cout << tmp << endl;
//cout << sum << endl;
if (tmp % sum == 0) cout << "Yes" << endl;
else cout << "No" << endl;
}
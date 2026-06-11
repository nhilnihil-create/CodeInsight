#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int M;
  int sum=0;
  cin >> N;
  M=N;
  
  sum = N % 10;
  
  while (N/10>0) {
    N /= 10;
    sum += N%10;
  }
  if (M%sum==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}

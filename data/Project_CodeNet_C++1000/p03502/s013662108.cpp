#include <bits/stdc++.h>
using namespace std;

int findSumOfDigits(int n){
 int sum = 0;
  while(n > 0){
   sum += n%10;
    n /= 10;
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
   int sum = findSumOfDigits(n);
    if(n%sum == 0){
      cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}

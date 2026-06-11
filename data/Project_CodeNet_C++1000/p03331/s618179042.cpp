#include <bits/stdc++.h>
using namespace std;

int sum_digit(int n){
  int sum=0;
  while (n>0){
    sum +=n%10;
    n = n/10;
  }
  return sum;
}

int main(){
  int n;
  cin >> n ;
  int ans = 1<<20;
  for (int a=1; a<n; a++){
    int b = n-a;
    int s = 0;
    s=sum_digit(a)+sum_digit(b);
    ans = ans > s ? s:ans;
  }
  cout << ans << endl;
}
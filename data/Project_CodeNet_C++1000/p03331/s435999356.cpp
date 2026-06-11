#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
#define ll long long 
int sumdigital(int n){
  int sum = 0;
  while(n>0){
    sum += n % 10;
    n /= 10;
  }
  return sum;  
}
using namespace std;
int main(){
  ll n;
  cin >> n;
  ll ans = 1000000000000000;
  for(int i = 1; i <= n/2+1; i++){
    int j = n-i;
    int sum = sumdigital(i)+sumdigital(j);
    if(sum < ans) ans = sum;
  }
  cout << ans << endl;
}
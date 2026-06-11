#include <bits/stdc++.h>
using namespace std;

int sums(int n){
  int r = 0; 
  while(n){
    r += n % 10;
    n /= 10;
  }
  return r;
}

int main(){
  int n, a, b;  cin >> n >> a >> b;
  int ans = 0;
  for(int i=1; i<=n; i++){
    int sumss = sums(i);
    if(a <= sumss && sumss <= b)  ans += i;
  }

  cout << ans << endl;
  return 0;
}

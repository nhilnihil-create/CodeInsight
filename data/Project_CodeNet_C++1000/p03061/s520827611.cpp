#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b, a % b);
  }
}

int main(){
  int n; 
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  vector<int> left(n+1, 0), right(n+1, 0);
  for(int i = 0; i < n; i++){
    left[i+1] = gcd(left[i], a[i]);
  }
  for(int i = n - 1; i >=0; i--){
    right[i] = gcd(a[i], right[i+1]);
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = max(ans, gcd(left[i], right[i+1]));
  }
  cout << ans << endl;
}

  
  
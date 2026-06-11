#include<bits/stdc++.h>
using namespace std;

bool y(int n){
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(n % i == 0) ans++;
  }
  return ans == 8;
}

int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(y(i) && i % 2 == 1) ans++;
  }
  cout << ans << endl;
}
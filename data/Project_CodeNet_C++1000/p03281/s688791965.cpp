#include<bits/stdc++.h>
using namespace std;

bool eight(int n){
  int y = 0;
  for(int i = 1; i <= n; i++){
    if(n % i == 0){
      y++;
    }
  }
  return y == 8;
}

int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2 == 1){
    if(eight(i)) ans++;
  }
  }
  cout << ans << endl;
}
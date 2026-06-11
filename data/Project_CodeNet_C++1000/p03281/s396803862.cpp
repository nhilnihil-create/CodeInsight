#include<bits/stdc++.h>
using namespace std;

bool yaku(int n){
  int re = 0;
  for(int i = 1; i <= n; i++){
    if(n % i == 0) re++;
  }
  return re == 8;
}

int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i += 2){
    if(yaku(i)) ans++;
  }
  cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  
  int ans = 0;
  for(int i = 3; i <= n; i+=2){
    int k = 0;
    for(int j = 1; j <= i; j++){
      if(i%j==0) k++;
    }
    if(k==8) ans++;
  }
  
  cout << ans << endl;
}
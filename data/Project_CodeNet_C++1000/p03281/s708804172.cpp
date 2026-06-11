#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  int ans = 0;
  for (int c=1; c<=N; c+=2){
    int div = 0;
    for (int i=1; i<=c; i++){
      if(c%i==0){
        div++;
      }
    }
    if(div==8){
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
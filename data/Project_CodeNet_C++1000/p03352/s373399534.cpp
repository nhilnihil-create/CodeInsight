#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0;
  if(n!=1){
  for(int i=2;i<=sqrt(n);i++){
    int a=1;
    while(pow(i,a)<=n){
      a++;
    }
    a=pow(i,a-1);
    ans=max(ans,a);
  }
  cout << ans << endl;
  }else{
    cout << 1 << endl;
  }
  return 0;
}
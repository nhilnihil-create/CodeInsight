#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i,ans=0;
  for(i=1;i<=n;i++){
    if(n>=i*i){
      ans=i*i;
    }else{
      break;
    }
  }
  cout << ans;
}

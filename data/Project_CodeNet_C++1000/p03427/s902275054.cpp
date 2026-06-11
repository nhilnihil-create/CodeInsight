#include<bits/stdc++.h>
using namespace std;


int main(){
  long long n;
  cin >> n;
  int keta=1;
  long long a=n;
  bool ha=true;
  long long c;
  while(1){
    if(a/10==0){
      c=a;
      break;
    }else{
      if(a%10!=9) ha=false;

      a=a/10;
      keta++;
    }
  }
  long long ans;
  if(ha==true){
    ans=c+9*(keta-1);
  }else{
    ans=c+9*(keta-1)-1;
  }
  cout << ans << endl;
  return 0;
}

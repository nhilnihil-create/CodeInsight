#include<iostream>
using namespace std;
int main(){
  int a,b,i;
  int ans=0;
  cin >> a >> b;
  for(i=0;i<2;i++){
    if(a>=b){
      ans=ans+a;
      a--;
    }
    else{
      ans=ans+b;
      b--;
    }
  }
  cout << ans << endl;
}
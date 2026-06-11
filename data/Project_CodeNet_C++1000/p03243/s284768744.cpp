#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=111;i<=999;i+=111){
    if(i-n<=110&&n<=i){
      cout<<i;
      return 0;
    }
  }
  return 0;
}

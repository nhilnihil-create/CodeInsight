#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  if (n<3){
    cout<<0<<endl;
  }else{
    int a=0;
  	while(n-3>=3)n-=3,a++;
    cout<<a+1<<endl;
  }
}
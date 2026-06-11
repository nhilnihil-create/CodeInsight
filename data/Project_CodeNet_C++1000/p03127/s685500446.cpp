#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main(){
  int n;cin>>n;
  int tmp1,tmp2;cin>>tmp1;
  for(int i=1;i<n;i++){
    cin>>tmp2;
    tmp1=gcd(tmp1,tmp2);
  }
  cout <<tmp1<<endl;
}
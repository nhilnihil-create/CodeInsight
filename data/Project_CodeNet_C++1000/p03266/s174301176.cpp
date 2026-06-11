#include <bits/stdc++.h>
using namespace std;

int main(){
  
  long long n,k;
  cin >>n>>k;
  
  long long ans=0;
 
  //kで割り切れるa,b,cの種類
  long long num1=n/k; 
  
  //kで割った余りがk/2になるa,b,cの種類
  long long num2=0;
  if(k%2==0){
    num2=(n+(k/2))/k;
  }
  ans=num1*num1*num1+num2*num2*num2;
  // cout <<"num1:"<<num1<<endl;
  // cout <<"num2:"<<num2<<endl;
  cout <<ans<<endl;
  return 0;
}
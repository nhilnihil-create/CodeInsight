#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b;
  cin>>a>>b;
  int64_t x;
  if(a%2==0){
    if(b%2==0)
      x=b^((b-a)/2%2);
    else
      x=(b-a+1)/2%2;
  }else{
    if(b%2==0)
      x=a^b^((b-a-1)/2%2);
    else
      x=a^((b-a)/2%2);
  }
  cout<<x<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  if(a+2*k-1<=b){
    for(int i=0;i<k;i++)
      cout<<a+i<<endl;
    for(int i=0;i<k;i++)
      cout<<b-k+1+i<<endl;
  }else
    for(int i=a;i<=b;i++)
      cout<<i<<endl;
}
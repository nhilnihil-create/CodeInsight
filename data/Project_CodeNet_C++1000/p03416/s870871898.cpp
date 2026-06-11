#include<iostream>
using namespace std;
int main(){

  int A,B;
  cin>>A>>B;
  int ans=0;
  int i10000=0;
  int i1000=0;
  int i100=0;
  int i10=0;
  int i1=0;
  for(int k=A;k<=B;k++){
  
    int i=k;
    i10000=i/10000;
    i-=i10000*10000;
    i1000=i/1000;
    i-=i1000*1000;
    i100=i/100;
    i-=i100*100;
    i10=i/10;
    i-=i10*10;
    i1=i;
    if(i10000==i1&&i1000==i10)ans++;
  }
  cout<<ans;
  return 0;
}
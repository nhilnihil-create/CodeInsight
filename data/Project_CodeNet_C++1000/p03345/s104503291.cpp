#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,C,K;
  cin>>A>>B>>C>>K;
  long long Af,Bf,Cf;
  for(int i=0;i<K;i++){
    Af=B+C;
    Bf=C+A;
    Cf=A+B;
    A=Af;
    B=Bf;
    C=Cf;
  }
  long long x=1;
  for(int i=0;i<18;i++)
    x*=10;
  if(A-B<=x && B-A<=x)
    cout<<A-B<<endl;
  else
    cout<<"Unfair"<<endl;
}
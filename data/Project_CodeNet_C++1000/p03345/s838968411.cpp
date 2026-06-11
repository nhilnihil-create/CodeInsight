#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  ll sa,sa1;
  if(k%2==0){
    sa=a-b;
  }else{
    sa=b-a;
  }
  sa1=sa;
  for(int i=1;i<=18;i++){
    sa1/=10;
  }
  if(sa1>0){
    cout<<"Unfair"<<endl;
  }else{
    cout<<sa<<endl;
  }
}
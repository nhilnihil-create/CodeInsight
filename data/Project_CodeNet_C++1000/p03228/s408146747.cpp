#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int a,b,k;
  cin>>a>>b>>k;
  for(i=0;i<k;i++){
    if(i%2==0){
      if(a%2==1)a--;
      a/=2;
      b+=a;
    }else{
      if(b%2==1)b--;
      b/=2;
      a+=b;
    }
  }
  cout<<a<<" "<<b;
}
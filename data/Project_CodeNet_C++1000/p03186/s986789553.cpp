#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  if(c-(a+b)>0){
    cout<<b+a+b+1<<endl;
  }else{
    cout<<b+c<<endl;
  }
}
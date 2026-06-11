#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c,k,am=1;
  cin>>a>>b>>c>>k;
  for(int j=1;j<=k;j++){
    am*=2;
  }
  if(max(max(a,b),c)==a){
    
    cout<<a*am+b+c<<endl;
  }
  else if(max(max(a,b),c)==b){
    cout<<b*am+a+c<<endl;
  }
  else if(max(max(a,b),c)==c){
    cout<<c*am+a+b<<endl;
  }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,k;
  cin>>a>>b>>c>>k;
  if(a>b){
    swap(a,b);
  }
  if(b>c){
    swap(b,c);
  }
  if(a>b){
    swap(a,b);
  }
  for(int i=0;i<k;i++){
    c*=2;
  }
  cout<<a+b+c<<endl;
}
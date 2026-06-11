#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int saidai=max({a,b,c});
  int all=a+b+c-saidai;
  for(int i=0;i<k;i++){
    saidai*=2;
  }
  cout<<all+saidai<<endl;
}
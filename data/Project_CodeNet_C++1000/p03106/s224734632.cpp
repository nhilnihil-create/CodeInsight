#include<bits/stdc++.h>
using namespace std;
int main() {
  int a,b,k,i,c;
  cin>>a>>b>>k;
  for(i=min(a,b);i>=1;i--){
    if(a%i==0&&b%i==0){
      c++;
      if(c==k){
        cout<<i<<endl;
        break;
      }
    }
  }
}
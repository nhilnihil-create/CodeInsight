#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,k,nm=0;
  cin>>a>>b>>k;
  int i=min(a,b);
  while(k!=nm){
    if(a%i==0&&b%i==0){
      nm++;
    }
    i--;
  }
  cout<<i+1<<endl;
}
    
 

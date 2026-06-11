#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;long x=0,y=0;
  for(char c:S){
    if(c=='A'||c=='T'||c=='C'||c=='G')x++;
    else {y=max(y,x);x=0;}
  }y=max(y,x);
  cout<<y;
}
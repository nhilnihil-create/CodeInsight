#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  int64_t m=0;
  int64_t a=0;
  int64_t r=0;
  int64_t c=0;
  int64_t h=0;
  for(int i=0;i<N;i++){
    string S;
    cin>>S;
    if(S.at(0)=='M') m++;
    if(S.at(0)=='A') a++;
    if(S.at(0)=='R') r++;
    if(S.at(0)=='C') c++;
    if(S.at(0)=='H') h++;
  }
  int64_t T=m*a*r+m*a*c+m*a*h+m*r*c+m*r*h+m*c*h;
  int64_t Q=a*r*c+a*r*h+a*c*h+r*c*h;
  cout<<T+Q<<endl;
    
    
    
}
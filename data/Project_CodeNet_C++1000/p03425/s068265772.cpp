#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,M=0,A=0,R=0,C=0,H=0;
  cin>>N;
  for(ll i=0;i<N;i++){
    string s;
    cin>>s;
    if(s.at(0)=='M'){M++;}
    if(s.at(0)=='A'){A++;}
    if(s.at(0)=='R'){R++;}
    if(s.at(0)=='C'){C++;}
    if(s.at(0)=='H'){H++;}
  }
  cout<<M*A*R+M*A*C+M*A*H+M*R*C+M*R*H+M*C*H+A*R*C+A*R*H+A*C*H+R*C*H<<endl;
}
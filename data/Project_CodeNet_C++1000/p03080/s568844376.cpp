#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0;string s;cin>>n>>s;
  for(int i=0;i<n;i++){
    if(s.at(i)=='R')a++;
  }
  if(a>n/2)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
 
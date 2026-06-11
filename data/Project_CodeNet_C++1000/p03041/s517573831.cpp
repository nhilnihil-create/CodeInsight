#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  k=k-1;
  string s;
  cin>>s;
  if(s.at(k)=='A'){
    s.at(k)='a';
  }
  else if(s.at(k)=='B'){
    s.at(k)='b';
  }
  else if(s.at(k)=='C'){
    s.at(k)='c';
  }
  cout<<s<<endl;
}

#include<bits/stdc++.h>
using namespace std;
signed main(){
  string s;
  cin>>s;
  if(s.size()==2){
    cout<<s<<"\n";
  }
  if(s.size()==3){
    swap(s[0],s[2]);
    cout<<s<<"\n";
  }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  if(s.size()==2){
    cout<<s<<'\n';
  }
  else{
    swap(s[0],s[2]);
    cout<<s<<'\n';
  }
  return 0;
}

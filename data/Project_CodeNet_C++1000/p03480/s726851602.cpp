#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int m=1000000;
  for(int i=1;i<s.size();i++){
    if(s[i]!=s[i-1]) m=min(m,max(i,(int)s.size()-i));
  }
  cout<<(m==1000000?(int)s.size():m);
}
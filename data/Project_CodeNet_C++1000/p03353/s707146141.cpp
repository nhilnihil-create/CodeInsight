#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int k,n,i,j;
  set<string> z;
  cin>>s>>k;
  n=s.length();
  for(i=0;i<n;i++) for(j=1;j<=min(n-i,5);j++) z.insert(s.substr(i,j));
  cout<<*next(z.begin(),k-1)<<endl;
}
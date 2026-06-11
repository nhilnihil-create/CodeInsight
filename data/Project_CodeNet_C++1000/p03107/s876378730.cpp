#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n,m=0,i;
  cin>>s;
  n=s.length();
  for(i=0;i<n;i++) if(s.at(i)=='0') m++;
  cout<<2*min(m,n-m)<<endl;
}
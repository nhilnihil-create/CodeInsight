#include <bits/stdc++.h>
using namespace std;
long long n,c,i,j,k,h,w,a,b;
string s;
int main(){
  cin>>s>>k;
  for(i=0;i<s.size();i++)if(s[i]!='1')break;
  if(k<=i)cout<<1;
  else cout<<s[i];
}
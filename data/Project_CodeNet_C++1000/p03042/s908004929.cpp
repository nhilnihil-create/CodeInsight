#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int a=(s[0]-'0')*10+s[1]-'0';
  int b=(s[2]-'0')*10+s[3]-'0';
  if(0<a&&a<=12&&0<b&&b<=12)cout<<"AMBIGUOUS"<<endl;
  else if(0<a&&a<=12)cout<<"MMYY"<<endl;
  else if(0<b&&b<=12)cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int cnt1=0,cnt2=0;
  int n=s.size();
  string a,b;
  rep(i,n){
    if(i%2==0){
      a+='0';
      b+='1';
    }
    else {
      a+='1';
      b+='0';
    }
  }
  rep(i,n){
    if(s[i]!=a[i])cnt1++;
    if(s[i]!=b[i])cnt2++;
  }
  cout<<min(cnt1,cnt2)<<endl;
}
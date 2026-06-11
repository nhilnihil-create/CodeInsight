#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;int w;cin>>s>>w;
  for(int i=0;i<s.size();i+=w)cout<<s[i];
  cout<<endl;
}
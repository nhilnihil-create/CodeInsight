#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s,t;cin>>s>>t;
  sort(all(s));
  sort(all(t));
  reverse(all(t));
  if(s<t)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c;cin>>a>>b>>c;
  if(a+b>=c)cout<<b+c<<endl;
  else cout<<a+b+b+1<<endl;
}
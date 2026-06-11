#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,a,b;cin>>n>>a>>b;
  int x=min(a,b),y=max(a+b-n,0);
  cout<<x<<" "<<y<<endl;
}
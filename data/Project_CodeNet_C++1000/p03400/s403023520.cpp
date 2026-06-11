#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,d,x;cin>>n>>d>>x;
  vector<int>a(n);
  int cnt=0;
  rep(i,n){
    cin>>a[i];
    cnt+=(d-1)/a[i]+1;
  }
  cout<<cnt+x<<endl;
}
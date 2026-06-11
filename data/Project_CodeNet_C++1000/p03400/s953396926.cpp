#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,d,x,s=0;
  cin>>n>>d>>x;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    s+=(d+a[i]-1)/a[i];
  }
  cout<<x+s<<endl;
}
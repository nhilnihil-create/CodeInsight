#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<ll> vec(90);
  vec[0]=2;
  vec[1]=1;
  for(int i=2;i<=n;i++){
    vec[i]=vec[i-1]+vec[i-2];
  }
  cout<<vec[n]<<endl;
}
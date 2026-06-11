#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  int n,m;cin>>n>>m;
  int ans=pow(2,m)*(100*(n-m)+1900*m);
  cout<<ans;
}
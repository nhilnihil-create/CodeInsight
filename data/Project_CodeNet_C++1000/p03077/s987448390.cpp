#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main() {
  ll n,a,b,c,d,e;cin>>n>>a>>b>>c>>d>>e;
  ll mn=min({a,b,c,d,e});
  cout<<(n+mn-1)/mn+4;    
}
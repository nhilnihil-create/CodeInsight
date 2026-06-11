#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
  int n,m;cin>>n>>m;
  int t = (n-m)*100 + m*1900;
  int p = 1;
  rep(i,m)p *= 2;
  cout << t*p << endl;
  return 0;
}
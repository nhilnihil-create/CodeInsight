#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,f[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  vector<int>v;
  v.pb(1);
  for(int i=9;i<=n;i*=9)v.pb(i);
  for(int i=6;i<=n;i*=6)v.pb(i);
  for(int i=1;i<=n;i++){
    f[i]=1e9;
    for(auto k:v){
      if(k<=i){
        f[i]=min(f[i],f[i-k]+1);
      }
    }
  }
  cout<<f[n]<<endl;
  return 0;
}
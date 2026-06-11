#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll gcd(ll m, ll n) {//最大公約数
    if (n == 0)return m;
    return gcd(n, m % n);
}//gcd

ll lcm(ll m, ll n) {//最小公倍数
    return m / gcd(m, n) * n;
}

int main(){
  int n; cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  int ans=a[0];
  rep(i,n-1){
    ans=gcd(ans,a[i+1]);
  }
  cout<<ans<<endl;
}



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main(){
 ll a,b,c,k;
  cin>>a>>b>>c>>k;
  ll y=max(a,b);
  ll n=max(c,y);
  ll p=n;
  n*=pow(2,k);
  cout<<a+b+c-p+n<<endl;
}


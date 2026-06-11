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
int main() {
    ll N;
  cin>>N;
  ll ans=0;
  vector<ll>A(N);
  rep(i,N){
cin>>A[i];
  }
  sort(A.begin(),A.end());
  ans=abs(A[N-1]-A[0]);
  cout<<ans<<endl;
}





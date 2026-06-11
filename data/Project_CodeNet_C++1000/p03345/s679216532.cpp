#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  ll A, B, C, K; cin >> A >>B >>C >>K;
  ll ans;
  if(K%2 == 0) ans = A-B;
  else ans = B-A;
  if(ans > 1e18) cout << "Unfair" << endl;
  else cout << ans << endl;
  return 0;
}
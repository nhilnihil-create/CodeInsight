#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
template <typename T, typename U>
using P = pair<T,U>;
template <typename T>
using vt = vector<T>;
using vvi = vector<vector<int>>;

int main(){
  int K,A,B;
  cin >> K >> A >> B;

  if (B - A <= 2 || A >= K)
  {
    cout << (ll)1+K << endl;
  }
  
  else
  {
    ll ans = A;
    K -= (A-1);
    ans += (ll)(B-A)*(K/2) + K%2;
    cout << ans << endl;    
  }

  return 0;
}
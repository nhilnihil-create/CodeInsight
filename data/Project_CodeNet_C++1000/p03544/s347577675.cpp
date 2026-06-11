#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  ll L0 = 2;
  ll L1 = 1;
  int N; cin >> N;
  if (N == 1) { cout << 1 <<  endl; return 0;} 
  ll ans;
  rep(i,N-1){
    ans = L0 + L1;
    swap(L0, L1);
    L1 = ans;
//    cout << ans << " ";
  }
// cout << endl;
  cout << ans << endl;
  return 0;
}
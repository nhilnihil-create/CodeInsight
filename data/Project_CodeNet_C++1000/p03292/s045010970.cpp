#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
int main() {
  cout << fixed << setprecision(10);
  int n = 3;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  sort(ALL(a));
  int ans = INF;
  do {
    ans = min(ans,abs(a.at(0)-a.at(1))+abs(a.at(1)-a.at(2)));
  } while(next_permutation(ALL(a)));
  cout << ans << endl;
}

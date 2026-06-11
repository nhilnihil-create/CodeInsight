#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int main(){
  int n,k; cin >> n >> k;
  ll ans = 0LL;
  for (int b = 1; b <= n; b++) {
    if(b-k <= 0) continue;
    ans += (b-k)*(n/b);
    if(k != 0) ans += max(n%b-(k-1),0);
    else ans += n%b;
  }
  std::cout << ans << '\n';
}

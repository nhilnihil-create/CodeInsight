#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n>>k;

  double ans = 0;
  repr(i,1,n+1){
    int x= i, c=0;
    while(x<k){
      x*=2;
      c++;
    }

    ans+= (1 / (double)n) * (1 / pow(2, c));
  }

  cout<<fixed<<setprecision(12)<<ans<<endl;
}

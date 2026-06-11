#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  ll ans = 0;
  rep(i, n) {
    int cnt = 2;
    if(a[i] == b[i]) cnt--;
    if(b[i] == c[i]) cnt--;
    if(c[i] == a[i]) cnt--;
    cnt = max(0, cnt);

    ans += cnt;
  }
  cout << ans << endl;
}
#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> ch(26);
  rep(i, n) {
    ch[s[i] - 'a']++;
  }
  ll ans = 1;
  rep(i, 26) {
   (ans *= ch[i] + 1) %= mod;
  }
  ans--;
  cout << ans << endl;
}
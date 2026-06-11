#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int MAX_T = 200050;
int main(){
  int n, C;
  cin >> n >> C;
  vector<int> s(n), t(n), c(n);
  rep(i, n) {
    int a, b, cc;
    cin >> a >> b >> cc;
    a *= 2;
    b *= 2;
    --cc;
    s[i] = a, t[i] = b, c[i] = cc;
  }
  
  vector<int> sum(200100);
  rep(i, C) {
    vector<int> imos(200100);
    rep(j, n) if(c[j] == i) imos[s[j] - 1]++, imos[t[j]]--;
    int t = 0;
    rep(j, MAX_T) {
      t += imos[j];
      if(t > 0) sum[j]++;
    }
  }
  int ans = 0;
  rep(j, MAX_T) {
    ans = max(sum[j], ans);
  }
  cout << ans << endl;
}
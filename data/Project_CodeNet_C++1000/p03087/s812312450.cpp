#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,q;
  string t,s = " ";
  cin >> n >> q >> t;
  s += t;
  vi cnt(n+1);
  for(int i=1; i<n; i++){
    if(s[i] == 'A' && s[i+1] == 'C'){
      cnt[i]++;
      cnt[i+1]++;
    }
  }
  rep(i,n-1) cnt[i+2] += cnt[i+1];
  //rep(i,n+1) cout << cnt[i] << endl;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    int ans = cnt[r]-cnt[l] +1;
    if(cnt[l]%2 == 0) ans--;
    ans /= 2;
    cout << ans << endl;
  }
}

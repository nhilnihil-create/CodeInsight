#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,m;
  cin >> n >> m;
  vi cnt(m+1,0);
  rep(i,n){
    int k;
    cin >> k;
    rep(j,k){
      int a;
      cin >> a;
      cnt[a]++;
    }
  }
  int ans=0;
  rep(i,m+1){
    if(cnt[i] == n) ans++;
  }
  cout << ans << endl;
}

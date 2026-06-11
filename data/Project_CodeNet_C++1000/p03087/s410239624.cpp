#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;
  vector<int> sum(n); sum[0] = 0;
  for(int i=1; i<n; i++){
    sum[i] = sum[i-1];
    if(s[i-1]=='A' && s[i]=='C') sum[i]++;
    //cout << sum[i] << endl;
  }
  
  rep(i,q){
    int l,r; cin >> l >> r;
    cout << sum[r-1] - sum[l-1] << endl;
  }
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    vector<ll> ab;
    rep(i,x)rep(j,y) {
      ab.push_back(a[i]+b[j]);
    }
    sort(ab.rbegin(), ab.rend());
    
    vector<ll> abc;
    for (int i = 0; i < min(k, (int)ab.size()); i++) {
      rep(j,z) {
        abc.push_back(ab[i]+c[j]);
      }
    }
    sort(abc.rbegin(), abc.rend());
    rep(i,k) cout << abc[i] << endl;
    return 0;
}
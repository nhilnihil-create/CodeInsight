#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> x(n+1);
    rep(i,n+1) cin >> x[i];
    sort(x.begin(), x.end());
    int ans = x[1]-x[0];
    rep(i,n) ans = __gcd(ans, x[i+1]-x[i]);
    cout << ans << endl;
}
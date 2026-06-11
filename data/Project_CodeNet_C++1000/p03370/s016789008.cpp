#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    rep(i,n) cin >> m[i];
    sort(m.begin(), m.end());
    rep(i,n) x -= m[i];
    int ans = n;
    ans += x/m[0];
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> v(3e5,0);
    int cnt = 1;
    int si = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i -1]) {
            v[si] = cnt;
            cnt = 1;
            si++;
        }else {
            cnt++;
        }
    }
    v[si] = cnt;
    si++;
    int a = 0;
    if (s[0] == '1') a++;
    int sa = 0;
    int sb;
    int sc;
    int ans = 0;
    rep(i, 2+2*(k-1)) sa += v[i];
    sb = v[2*k];
    ans = sa + sb*a;
    for (int i = 1; i< si; i++) {
        //cout << ans << endl;
        sa += v[i + 1 + 2*(k-1)] - v[i-1];
        sb = v[2*k + i];
        ans = max(ans, sa + sb*((a+i)%2));
    }
    
    cout << ans << endl;
    return 0;
}

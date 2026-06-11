#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

using ll = long long;

int main() {
    string S;
    cin >> S;

    int n = S.size();

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (S[i] == 'W') {
            ans += (i - cnt);
            cnt ++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    ll N = S.size();
    ll ans = 0;
    ll sum = 0;

    bool check = 1;

    for(ll i = 0; i < N; i++) {
        if(S.at(i) == 'W') {
            ans += i;
            sum++;
        }
    }
    cout << ans - sum*(sum - 1)/2 << endl;
    return 0;

    while(0) {
        check = 0;
        for(ll i = 0; i < N - 1; i++) {
            if(S.at(i) == 'B' && S.at(i + 1) == 'W') {
                S.at(i) = 'W';
                S.at(i + 1) = 'B';
                check = 1;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
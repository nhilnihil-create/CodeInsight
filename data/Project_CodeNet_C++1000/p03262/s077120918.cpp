#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(min(a, b) == 0)return max(a, b);
    return gcd(min(a, b), max(a, b)%min(a, b));
}

int main() {
    ll N = 0;
    cin >> N;
    ll X;
    cin >> X;
    vector<ll> A(N + 1,X);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    if(N == 1) {
        cout << abs(A.at(1) - A.at(0)) << endl;
        return 0;
    }
    sort(A.begin(),A.end());
    for(ll i = 0; i < N; i++) {
        A.at(i) = A.at(i + 1) - A.at(i);
    }
    for(int i = 0; i < N + 1; i++) {
        //cout << A.at(i);
    }
    //cout << endl;
    ll ans = 1e18;
    if(N == 1) {
        cout << abs(A.at(1) - A.at(0)) << endl;
        return 0;
    }
    for(ll i = 0; i < N - 1; i++) {
        ans = min(ans, gcd(A.at(i), A.at(i + 1)));
        //cout << A.at(i) << ':' << A.at(i + 1) << '=' << gcd(A.at(i), A.at(i + 1)) << endl;
        //cout << ans << endl;
    }
    cout << ans << endl;



    return 0;
}
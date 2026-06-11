#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0, M;
    cin >> N >> M;
    ll ans = 0;
    vector<pair<ll, ll> > A(N);
    for(ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        A.at(i) = make_pair(a, b);
    }
    sort(A.begin(),A.end());
    for(ll i = 0; i < N; i++) {
        if(M <= A.at(i).second) {
            ans += M*A.at(i).first;
            break;
        }
        ans +=A.at(i).first*A.at(i).second;
        M -= A.at(i).second;
    }

    cout << ans << endl;



    return 0;
}
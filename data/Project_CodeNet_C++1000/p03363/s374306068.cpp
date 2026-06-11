#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }

    vector<ll> S(N+1);
    for (int i = 1; i <= N; i++){
        S[i] = S[i-1] + A[i-1];
    }

    map<ll, ll> m;
    rep(i, N+1){
        m[S[i]]++;
    }

    ll ans = 0;
    for(auto p : m){
        auto value = p.second;
        ans += (value * (value-1)) / 2;
    }

    cout << ans << endl;

    return 0;
}
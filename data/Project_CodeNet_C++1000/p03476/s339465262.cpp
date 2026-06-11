#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int Q;
    cin >> Q;
    vector<int> l(Q), r(Q);
    rep(i,Q) cin >> l[i] >> r[i];
    
    vector<int> prime_v(100000);
    for (int i = 3; i <= 100000; i += 2) {
        if(is_prime(i) && is_prime((i+1)/2)) ++prime_v[i];
    }
    for (int i = 3; i <= 100000; i += 2) prime_v[i] += prime_v[i-2];

    rep(i,Q) {
        if (l[i] == 1) cout << prime_v[r[i]] << endl;
        else cout << prime_v[r[i]] - prime_v[l[i]-2] << endl;
    }
}


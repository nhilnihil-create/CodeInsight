#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    ll N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    ll L = N * M / __gcd(N, M);
    bool ok = true;
    ll baseN = N / __gcd(N, M);
    ll baseM = M / __gcd(N, M);
    for (int i = 0; i * baseN * baseM < L; ++i) {
        if (S.at(baseN * i) != T.at(baseM * i)) {
            ok = false;
            break;
        }
    }
    if (ok) cout << L << endl;
    else cout << -1 << endl;
}

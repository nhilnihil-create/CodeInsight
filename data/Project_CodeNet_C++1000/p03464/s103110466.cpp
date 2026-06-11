#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

const int MX_K = 1e5+5;

int K, A[MX_K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    FOR(i,1,K) cin >> A[i];

    array<long long,2> N = { 2,2 };
    bool rip = 0;
    RFOR(i,K,1){
        array<long long,2> x = { (N[0]+A[i]-1)/A[i] * A[i], N[1]/A[i] * A[i] };
        if (x[0] <= N[1]) N = x, N[1] += A[i]-1;
        else rip = 1;
    }
    if (rip) cout << -1;
    else cout << N[0] << ' ' << N[1];
}

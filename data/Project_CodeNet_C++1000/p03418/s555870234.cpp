#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    ll N, K;
    cin >> N >> K;
    ll res = 0;
    if (K == 0)
        res += (1 + (N - K - 1)) * (N - K - 1) / 2;
    else
        res += (1 + (N - K)) * (N - K) / 2;

    for (int i = K + 1; i <= N; i++) {
        ll katamari = N / i - 1;
        ll amari = N % i;
        ll kosuu = i - K;
        res += katamari * kosuu;
        if (amari >= K)
            res += amari - K + 1;
    }

    cout << res << endl;
}
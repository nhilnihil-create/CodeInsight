#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

ll F[90];
ll fibonacchi(ll n) {
    if (n == 0)
        return F[n] = 2;
    if (n == 1)
        return F[n] = 1;
    if (F[n] != -1)
        return F[n];
    else
        return F[n] = fibonacchi(n - 1) + fibonacchi(n - 2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    memset(F, -1, sizeof(F));
    cout << fibonacchi(N) << endl;

    return 0;
}
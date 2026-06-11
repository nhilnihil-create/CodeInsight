#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    long long N, M;
    cin >> N >> M;
    string s1, s2;
    cin >> s1 >> s2;
    long long g = GCD(N, M);
    long long res = N / g * M;
    N /= g, M /= g;
    bool judge = true;
    for (long long i = 0; i < g; ++i) {
        if (s1[i * N] != s2[i * M])
            judge = false;
    }

    if (judge)
        cout << res << endl;
    else
        cout << -1 << endl;
}
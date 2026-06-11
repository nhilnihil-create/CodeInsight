#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<std::string> S) {
    ll m = 0, a = 0, r = 0, c = 0, h = 0;
    rep(i, N) {
        if (S[i][0] == 'M') {
            m++;
        } else if (S[i][0] == 'A') {
            a++;
        } else if (S[i][0] == 'R') {
            r++;
        } else if (S[i][0] == 'C') {
            c++;
        } else if (S[i][0] == 'H') {
            h++;
        }
    }
    cout << m * a * r + m * a * c + m * a * h + m * r * c + m * r * h + m * c * h + a * r * c + a * r * h + a * c * h +
                r * c * h
         << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}

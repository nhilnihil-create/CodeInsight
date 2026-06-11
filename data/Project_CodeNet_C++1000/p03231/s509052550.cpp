#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    long long N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    long long GCD = gcd(N, M), LCM = N / GCD * M, RS = M / GCD, RT = N / GCD;
    map<long long, char> keep;

    bool exist = true;
    for (long long i = 0; i < N; i++) {
        keep[RS * i] = S.at(i);
    }
    for (long long i = 0; i < M; i++) {
        keep[RT * i] = T.at(i);
    }
    for (long long i = 0; i < N; i++) {
        if (keep.count(RS * i) && keep.at(RS * i) != S.at(i)) {
            exist = false;
        }
    }

    if (exist) {
        cout << LCM << endl;
    }
    else {
        cout << -1 << endl;
    }
}
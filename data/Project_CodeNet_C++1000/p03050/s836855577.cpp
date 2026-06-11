#include <bits/stdc++.h>

using namespace std;
#ifdef CLION
ifstream ifs("/home/kyuridenamida/CLionProjects/untitled4/input.txt");
#define cin ifs
#endif

int main() {
    long long N;
    cin >> N;


    set<long long> S;

    for (long long i = 1; i * i <= N; i++) {
        S.insert(i);
        S.insert(N / i);
    }

    long long ans = 0;
    S.insert(0);
    for (auto s : S) {
        long long small = s + 1;
        long long d = N / small;
        if (d == 0) {
            continue;
        }
        long long X = N % small;

        if ((X - d) >= 0 && (X - d) % d == 0) {
            ans += small + (X - d) / d;
        }
    }
    cout << ans << endl;

}


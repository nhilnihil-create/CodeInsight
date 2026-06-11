#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S;
    cin >> T;
    ll g = (M*N)/__gcd(N, M);

    if (S[0] != T[0]) {
        cout << -1 << endl;
        return 0;
    } else {
        if (g == M*N) {
            cout << g << endl;
            return 0;
        } else {
            int a = g/N;
            int b = g/M;
            int i = a;
            int j = b;
            while (i < M && j < N) {
                if (S[j] != T[i]) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    i += a;
                    j += b;
                }
            }
            cout << g << endl;
            return 0;
        }
    }
}

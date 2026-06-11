#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> C(N - 1);
    vector<int> S(N - 1);
    vector<int> F(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> C[i] >> S[i] >> F[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int time = 0;
        for (int j = i; j < N - 1; j++) {
            if (time < S[j]) {
                time = S[j];
            } else if ((time - S[j]) % F[j] != 0) {
                time += F[j] - (time - S[j]) % F[j];
            }
            time += C[j];
        }
        cout << time << endl;
    }
    cout << 0 << endl;

    return 0;
}

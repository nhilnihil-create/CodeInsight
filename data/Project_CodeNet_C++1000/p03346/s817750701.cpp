#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        p--;
        P[p] = i;
    }

    int t = 1, ans = 1;
    for (int i = 1; i < N; i++) {
        if (P[i] > P[i - 1]) {
            t++;
        } else {
            t = 1;
        }

        ans = max(ans, t);
    }
    cout << N - ans << endl;
}

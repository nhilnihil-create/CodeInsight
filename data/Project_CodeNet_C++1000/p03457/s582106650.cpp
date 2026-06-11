#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N), x(N), y(N);
    for (int i = 0; i < N; i++) cin >> t[i] >> x[i] >> y[i];

    int pret = 0, prex = 0, prey = 0;
    bool ans = true;
    for (int i = 0; i < N; i++) {
        int dt = t[i] - pret;
        int dx = abs(x[i] - prex);
        int dy = abs(y[i] - prey);
        if (dt < dx + dy || dt % 2 != (dx + dy) % 2) {
            ans = false;
            break;
        }
        pret = t[i], prex = x[i], prey = y[i];
    }

    cout << (ans ? "Yes" : "No") << endl;
}
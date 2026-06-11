#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> drink(N);
    int A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        drink[i] = make_pair(A, B);
    }

    sort(drink.begin(), drink.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = min(drink[i].second, M);
        ans += (long long)drink[i].first * tmp;
        M -= tmp;
        if (M == 0) break;
    }

    cout << ans << endl;
}
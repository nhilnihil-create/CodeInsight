#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> ds;
    for (int i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            ds.push_back(i);
            ds.push_back(M / i);
        }
    }

    int ans = 0;
    for (int d : ds) {
        if (M / d >= N) {
            ans = max(ans, d);
        }
    }
    cout << ans << endl;
}

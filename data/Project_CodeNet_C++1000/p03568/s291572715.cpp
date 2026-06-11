#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    unsigned int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) cnt++;
    }

    auto ans = (int) pow(3, N) - (1u << cnt);
    cout << ans << endl;
    return 0;
}
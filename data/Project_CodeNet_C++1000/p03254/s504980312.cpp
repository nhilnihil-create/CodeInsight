#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, x;
    cin >> N >> x;
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);
    sort(a.begin(), a.end());

    int64_t ans = 0; 
    for (int i = 0; i < N; i++) {
        if (x >= a.at(i)) ans++, x -= a.at(i);
        else break;
    }

    if (ans == N && x > 0) ans--;
    cout << ans << endl;
}
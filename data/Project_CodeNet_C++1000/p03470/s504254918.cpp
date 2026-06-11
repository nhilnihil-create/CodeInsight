#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, ans = 1;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; ++i) {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end(), greater<int>());

    int current = d[0];
    for (auto s : d) {
        if (current > s) {
            ans++;
            current = s;
        }
    }
    cout << ans << endl;
}
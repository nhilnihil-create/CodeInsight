#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];

    int ans = 0;
    while (1) {
        if (*max_element(h.begin(), h.end()) == 0) break;
        int l = 0;
        while (h[l] == 0) l++;
        int r = l + 1;
        while (r < N && h[r] > 0) r++;
        for (int i = l; i < r; i++) h[i]--;
        ans++;
    }

    cout << ans << endl;
}
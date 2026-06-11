#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> h(N + 1,0);
    for(int i = 0; i < N; i++) {
        cin >> h.at(i);
    }

    int ans = 0;

    for(int i = 0; i < *max_element(h.begin(), h.end()); i++) {
        for(int j = 1; j < N + 1; j++) {
            if(h.at(j) <= i && h.at(j - 1) > i) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
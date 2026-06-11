#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> CT(N);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        CT[i] = make_pair(b, a);
    }
    int ans = 100000000;
    int index = -1;
    for(int i = 0; i < N; i++) {
        if(CT[i].first <= T) {
            if(CT[i].second < ans) {
                index = i+1;
            }
            ans = min(ans, CT[i].second);
        }
    }
    if(index == -1) {
        cout << "TLE" << endl;
        return 0;
    }
    cout << ans << endl;
}
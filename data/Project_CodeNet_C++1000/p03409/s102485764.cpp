#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<pair<int, int>> red(N), blue(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        red[i] = make_pair(a, b); //(x, y)
    }
    for (int i = 0; i < N; i++) {
        int c, d; cin >> c >> d;
        blue[i] = make_pair(c, d); //(x, y)
    }

    sort(blue.begin(), blue.end());
    
    vector<bool> use(N);
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int ma = -1, maxj;
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (red[j].first < blue[i].first && red[j].second < blue[i].second && red[j].second > ma && !use[j]) {
                ma = red[j].second;
                maxj = j;
                flag = true;
            }
        }
        if (flag) {
            use[maxj] = true;
            ans++;
        }
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}
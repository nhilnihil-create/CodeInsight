#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> F[101];
    vector<int> P[101];
    ll ans = -100000000000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            int x;
            cin >> x;
            F[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 10; j++) {
            int x;
            cin >> x;
            P[i].push_back(x);
        }
    }

    for (int bits = 0; bits < (1<<10); bits++) {
        vector<int>v;
        for (int i = 0; i < 10; i++) {
            if (bits&(1<<i)) {
                v.push_back(i);
            }
        }
        if (v.size() == 0) {
            continue;
        }
        ll profit = 0;
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < v.size(); j++) {
                if (F[i][v[j]] == 1) {
                    cnt++;
                }
            }
            profit += P[i][cnt];
        }
        if (profit > ans) {
            ans = profit;
        } 
    }
    cout << ans << endl;
}

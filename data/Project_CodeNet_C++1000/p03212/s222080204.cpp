#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;

    int d[3] = { 3,5,7 };
    int ans = 0;
    int i = 0;
    while (true) {
        vector<int> X;
        int p = i++;
        int c[3] = {};
        while (p >= 3) {
            X.push_back(d[p % 3]);
            c[p % 3]++;
            p /= 3;
        }
        if (p != 1) continue;
        if (c[0] * c[1] * c[2] == 0) continue;
        LL tmp = 0;
        reverse(X.begin(), X.end());
        for (int x : X) tmp = tmp * 10 + x;
        if (tmp > N) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
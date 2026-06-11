#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    vector<int> P;
    for (int i = 2; i <= N; i++) {
        bool ok = true;
        for (int p : P) if (i % p == 0) ok = false;
        if (ok)P.push_back(i);
    }

    vector<int> I(P.size());
    rep(i, P.size()) {
        int n = N, p = P[i];
        while (n >= p) { I[i] += n / p; n /= p; }
    }

    int ans = 0;

    rep(i, I.size()) rep(j, I.size()) rep(k, I.size()) {
        if (i == j || j == k || i == k) continue;
        if (I[i] < 4 || I[j] < 4 || I[k] < 2) continue;
        if (i > j) continue;
        ans++;
    }
    rep(i, I.size()) rep(j, I.size()){
        if (i == j) continue;
        if (I[i] < 14 || I[j] < 4) continue;
        ans++;
    }
    rep(i, I.size()) rep(j, I.size()) {
        if (i == j) continue;
        if (I[i] < 24 || I[j] < 2) continue;
        ans++;
    }
    rep(i, I.size()) {
        if (I[i] < 74) continue;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;



int main() {
    ull N, M;
    cin >> N >> M;

    ull ai, accA[N+1] = {};
    map<ull, ull> cntM{};
    cntM[0] = 1;
    rep(i, N) {
        cin >> ai;
        accA[i+1] = (accA[i] + ai) % M;
        cntM[accA[i+1]]++;
    }

    ull ans = 0;
    for (auto itr = cntM.begin(); itr != cntM.end(); itr++) {
        ull cnt = itr->second;
        if (cnt > 0) 
            ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}

 
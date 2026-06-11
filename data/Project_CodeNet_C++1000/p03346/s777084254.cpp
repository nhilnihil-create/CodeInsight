#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    int N;
    cin >> N;
    vector<pll> P(N);
    rep(i, N) {
        int a;
        cin >> a;
        P[i] = {a, i};
    }

    sort(all(P));

    int r = 0, tmp = 0, cnt = 0;
    while (r + 1 <= N - 1) {
        if (P[r].second <= P[r + 1].second)
            cnt++, r++;
        else
            tmp = max(tmp, cnt + 1), r++, cnt = 0;
    }
    tmp = max(tmp, cnt + 1);

    cout << N - tmp << endl;
}
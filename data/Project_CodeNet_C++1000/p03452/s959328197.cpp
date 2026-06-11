#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
const i64 INF = 1e16;
using T = vector<vector<tuple<int, int>>>;
vector<i64> x;
T data;

void recursive(int i) {
    for (auto a : data[i]) {
        int p, d;
        tie(p, d) = a;
        if (x[p] == INF) {
            x[p] = x[i] + d;
            recursive(p);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    data = T(N);
    for(int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        data[l].push_back(make_tuple(r, d));
        data[r].push_back(make_tuple(l, -d));
    }
    x = vector<i64>(N, INF);
    bool ans = true;
    for(int i = 0; i < N; i++) {
        if(x[i] == INF) {
            x[i] = 0;
            recursive(i);
        }
    }
    for(int i = 0; i < N; i++) {
        for(auto a : data[i]) {
            int p, d;
            tie(p, d) = a;
            ans &= x[i] + d == x[p];
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
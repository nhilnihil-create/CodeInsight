#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N;
    cin >> N;
    using t = tuple<int,int,int>;
    vector<t> V;
    rep(i,N) {
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back(make_tuple(a,b,c));
    }
    sort(V.begin(), V.end(), [](const t &left, const t &right){return get<2>(left) > get<2>(right);});
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            t D = V[0]; 
            int H = get<2>(D) + abs(cx - get<0>(D)) + abs(cy - get<1>(D));
            bool found = true;
            for (int i = 1; i < N; i++) {
                t D = V[i];
                int x = get<0>(D), y = get<1>(D), h = get<2>(D);
                if (h != max(H - abs(cx - x) - abs(cy - y), 0)) {
                    found = false;
                    break;
                }
            }
            if (found) {
                printf("%d %d %d\n", cx, cy, H);
                return 0;
            }
        }
    }
}
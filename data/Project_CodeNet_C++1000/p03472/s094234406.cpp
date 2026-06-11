#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, H; cin >> N >> H;
    vector B(N,0);
    int am = 0;
    rep(i,N) {
        int a, b; cin >> a >> b;
        B.at(i) = b;
        am = max(am, a);
    }
    sort(B.begin(), B.end());

    ll res = 0;
    while (H > am && am < B.back()) {
        H -= B.back(); B.pop_back();
        res++;
    }
    res += ((ll)H + am - 1) / am;
    cout << res << endl;
}

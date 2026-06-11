#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    int l, r;
    int L = 0, R = N;

    for(int i = 0; i < M; i++) {
        cin >> l >> r;
        L = max(L,l);
        R = min(R,r);
        //cout << l << ',' << r << endl;
    }
    cout << (R - L >= 0)*(R - L + 1) << endl;

    return 0;
}
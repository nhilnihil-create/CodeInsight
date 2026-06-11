#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    int L = 0;
    int R = N;
    rep(i, M){
        int l, r; cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
    }

    if(R - L >= 0){
        cout << R-L+1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
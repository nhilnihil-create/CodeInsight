#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {
    int N, X;
    cin >> N >> X;

    int mi = 1001;

    int cnt = 0;

    rep(i, N) {
        int m;
        cin >> m;
        X -= m;
        mi = min(mi, m);
        cnt++;
    }

    cout << cnt + X / mi << endl;


    return 0;
}
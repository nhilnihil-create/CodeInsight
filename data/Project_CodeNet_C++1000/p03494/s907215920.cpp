#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

const int INF = 1000000;

int main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];

    int res = INF;

    rep(i, N) {
        int count = 0;
        while (A[i]%2 == 0) {
            A[i] /= 2;
            ++count;
        }
        if (res > count) res = count;
    }

    cout << res << endl;

    return 0;
}


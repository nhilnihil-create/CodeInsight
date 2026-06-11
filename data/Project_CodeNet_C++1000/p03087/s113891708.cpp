#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, Q;
string S;
vector<int> L, R;

vector<int> w;


void input() {
    cin >> N >> Q >> S;
    L = R = vector<int>(Q);
    rep(i, Q) cin >> L[i] >> R[i];
}


int main() {
    input();
    w = vector<int>(N + 1, 0);
    bool a = false;
    rep(i, N) {
        w[i + 1] = w[i];
        if (S[i] == 'A') {
            a = true;
        } else {
            if (a && S[i] == 'C') w[i + 1]++;
            a = false;
        }
    }
    rep(i, Q) {
        int l = L[i], r = R[i];
        int ans = w[r] - w[l];
        cout << ans << endl;
    }
}

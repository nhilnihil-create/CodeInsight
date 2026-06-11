#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

vector<int> LISLDS(const int N, const int A, const int B) {
    vector<int> ret;
    for(int i = B - 1; i >= 0; i--)
        ret.push_back(i);

    int n = N - B;
    int a = A - 1;
    if(a == 0) return ret;

    rep(i, a) {
        int siz = ret.size();
        for(int j = n / a - (i < n % a ? 0 : 1); j >= 0; j--)
            ret.push_back(siz + j);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, A, B;
    cin >> N >> A >> B;
    if(A + B > N + 1 || (ll)A * B < N) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ret = LISLDS(N, A, B);

    rep(i, ret.size()) cout << ret[i] + 1 << " ";
    cout << endl;

    return 0;
}
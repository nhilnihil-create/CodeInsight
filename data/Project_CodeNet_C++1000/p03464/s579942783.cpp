#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

bool isok1(ll x, vector<int> &A) {
    int K = A.size();
    for (int i = 0; i < K && x >= 2; ++i)
        x -= x % A[i];
    return x >= 2;
}

ll misearch(vector<int> &A) {
    ll ok = 1e15, ng = 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        (isok1(mid, A) ? ok : ng) = mid;
    }
    return ok;
}

bool isok2(ll x, vector<int> &A) {
    int K = A.size();
    for (int i = 0; i < K && x > 2; ++i)
        x -= x % A[i];
    return x <= 2;
}

ll masearch(vector<int> &A) {
    ll ok = 1, ng = 1e15;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        (isok2(mid, A) ? ok : ng) = mid;
    }
    return ok;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    ll mi = misearch(A);
    ll ma = masearch(A);

    if (mi > ma)
        cout << -1 << endl;
    else
        cout << mi << " " << ma << endl;

    return 0;
}

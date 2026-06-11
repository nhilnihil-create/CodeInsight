#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++) cin >> X.at(i);

    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }

    sort (X.begin(), X.end());

    vector<int> diff(M - 1);
    vector<P> diff_sort(M - 1);
    for (int i = 0; i < M - 1; i++) {
        diff.at(i) = abs(X.at(i + 1) - X.at(i));
        diff_sort.at(i) = make_pair(diff.at(i), i);
    }
    sort(diff_sort.begin(), diff_sort.end());//, greater<ll>());

    for (int i = 0; i < N - 1; i++) {
        ll tmp = diff_sort.at(M - 2 - i).second;
        diff.at(tmp) = 0;
    }

    ll ans = accumulate(diff.begin(), diff.end(), 0LL);
    cout << ans << endl;

    return 0;
}

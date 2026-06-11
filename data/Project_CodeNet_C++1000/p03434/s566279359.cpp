#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    vector<int> a(N);
    rep(i,N) cin >> a[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int alice = 0;
    int bob = 0;

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) alice += a[i];
        else bob += a[i];
    }

    cout << alice - bob << endl;
    return 0;
}
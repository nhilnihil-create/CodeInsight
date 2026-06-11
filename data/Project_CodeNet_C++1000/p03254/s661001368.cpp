#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, x;
    cin >> N >> x;

    vector<int> a(N);
    rep (i,N) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (i == N - 1 && x > a.at(i)) {
            break;
        }

        if (x <= 0) {
            break;
        }
        if (x >= a.at(i)) {
            ++res;
            x -= a.at(i);
        } else {
            break;
        }

    }
    cout << res << endl;


}

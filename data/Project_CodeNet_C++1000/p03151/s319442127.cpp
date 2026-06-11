#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), diff;
    ll lack = 0;
    ll excess = 0;
    int ans = 0;
    rep(i,N) cin >> A.at(i);
    rep(i,N) cin >> B.at(i);
    rep(i,N) {
        if (A.at(i) < B.at(i)) {
            ++ans;
            lack += B.at(i) - A.at(i);
        }
        else if (A.at(i) > B.at(i)) {
            excess += A.at(i) - B.at(i);
            diff.push_back(A.at(i) - B.at(i));
        }
    }
    if (!diff.empty()) sort(diff.begin(), diff.end(), greater<ll>());
    if (lack > excess) cout << -1 << endl;
    else {
        int i = 0;
        while (lack > 0) {
            ++ans;
            lack -= diff.at(i);
            ++i;
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), tmp(N);
    rep(i,N) {
        cin >> X.at(i);
        tmp.at(i) = X.at(i);
    }
    int ans;
    sort(tmp.begin(), tmp.end());
    rep (i,N) {
        if (X.at(i) <= tmp.at(N / 2 - 1)) {
            ans = tmp.at(N / 2);
        } else {
            ans = tmp.at(N / 2 - 1);
        }
        cout << ans << endl;
    }
}

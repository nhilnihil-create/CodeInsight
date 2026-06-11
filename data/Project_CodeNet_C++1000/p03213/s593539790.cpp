#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

map<int,ll> ndiv;

int num(int x) {
    int cnt = 0;
    for (auto it = ndiv.begin(); it != ndiv.end(); it++) {
        int val = it->second;
        if (val >= x-1) {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    ll n;
    cin >> n;

    rep(i,n) {
        int t = i + 1;
        int d = 2;
        while (t != 1) {
            while (t % d == 0) {
                t /= d;
                ndiv[d]++;
            }
            d++;
        }
    }

    cout << num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) + num(5) * (num(5) - 1) * (num(3) - 2) / 2<< endl;

}

int main() {
    solve();
    return 0;
}

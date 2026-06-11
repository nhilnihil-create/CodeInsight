#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, a;
    cin >> N;
    map<int, int> mp;
    rep(i,N) {
        cin >> a;
        ++mp[a];
    }
    int ans = 0;
    for (auto x : mp) {
        if (x.first <= x.second) {
            ans += x.second - x.first;
        } else {
            ans += x.second;
        }
    }
    cout << ans << endl;
}

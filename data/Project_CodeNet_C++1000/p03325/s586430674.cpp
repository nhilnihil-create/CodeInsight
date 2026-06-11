#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    int ans = 0;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a.at(i);
    rep(i,N) {
        while (a.at(i) > 0) {
            if (a.at(i) % 2 == 0) {
                ++ans;
                a.at(i) /= 2;
            } else break;
        }
    }
    cout << ans << endl;
}

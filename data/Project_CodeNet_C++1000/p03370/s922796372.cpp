#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, X;
    cin >> N >> X;

    vector<int> v(N);
    rep(i, N) {
        cin >> v.at(i);
        X -= v.at(i);
    }

    int res = N;
    sort(v.begin(), v.end());
    res += X / v.at(0);

    cout << res << endl;
}

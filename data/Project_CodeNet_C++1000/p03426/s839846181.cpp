#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vector<P> a(h * w);
    rep(i, h)rep(j, w){
        int A;
        cin >> A;
        A--;
        a[A] = make_pair(i, j);
    }

    vector<int> cost(h * w, 0);
    for(int i = d; i <= h * w; i++){
        cost[i] = cost[i - d];
        cost[i] += abs(a[i].first - a[i - d].first) + abs(a[i].second - a[i - d].second);
    }

    int q;
    cin >> q;
    rep(i, q){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << cost[r] - cost[l] << endl;
    }
}
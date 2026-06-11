//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vi p(n), p_(n);
    rep(i, n) {
        cin >> p[i];
        --p[i];
        p_[p[i]] = i;
    }

    int ans = 0;
    int now = 0;
    rep(i, n-1) {
        if(p_[i] < p_[i+1]) {
            now++;
        } else {
            ans = max(ans, now);
            now = 0;
        }
    }
    ans = max(ans, now);
    cout << n-1-ans << endl;
}
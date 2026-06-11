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
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vi p_(n);
    rep(i, n) {
        int p;
        cin >> p;
        --p;
        p_[p] = i;
    }

    int ans = 0;
    int now = 1;
    rep(i, n-1) {
        if(p_[i] < p_[i+1]) {
            now++;
        } else {
            ans = max(ans, now);
            now = 1;
        }
    }
    ans = max(now, ans);

    cout << n-ans << endl;
}
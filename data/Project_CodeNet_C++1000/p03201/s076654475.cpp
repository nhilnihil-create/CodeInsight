//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    multiset<int> s(all(a));
    int ans = 0;
    while(!s.empty()) {
        auto it = prev(s.end());
        int y = *it;
        s.erase(it);
        int x = (1 << (32 - __builtin_clz(y))) - y;
        auto it_ = s.find(x);
        if(it_ != s.end()) {
            ++ans;
            s.erase(it_);
        } 
        
    }

    cout << ans << '\n';
}
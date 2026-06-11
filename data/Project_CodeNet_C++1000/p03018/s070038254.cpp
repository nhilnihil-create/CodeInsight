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
    string s;
    cin >> s;

    int num = s.size()-2;
    ll ans = 0LL;
    ll kk = 0LL;
    rep(i, num) {
        if(s[i] == 'A') {
            kk++;
            if(s.substr(i, 3) == "ABC") {
                ans += kk;
                --kk;
                s[++i + 1] = 'A';
            }
        } else {
            kk = 0LL;
        }
    }

    cout << ans << endl;
}
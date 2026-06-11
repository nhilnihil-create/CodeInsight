#include<bits/stdc++.h>

using namespace std;

int main() {
    constexpr long MOD = 1e9 + 7;

    long n,q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<pair<string, string>> td(q);
    for(auto &x: td) cin >> x.first >> x.second;

    long lok = -1, lng = n;
    while(lng - lok > 1) {
        long m = (lok+lng)/2;

        long cur = m;
        for(auto &x: td) {
            if(cur < 0 || n <= cur) break;

            char t = x.first[0];
            char d = x.second[0];
            if(s[cur] == t)
                cur += d == 'L' ? -1 : 1;
        }
        if(cur < 0)
            lok = m;
        else
            lng = m;
    }

    long rok = n, rng = -1;
    while(rok - rng > 1) {
        long m = (rok+rng)/2;

        long cur = m;
        for(auto &x: td) {
            if(cur < 0 || n <= cur) break;

            char t = x.first[0];
            char d = x.second[0];
            if(s[cur] == t)
                cur += d == 'L' ? -1 : 1;
        }
        if(n <= cur)
            rok = m;
        else
            rng = m;
    }

    cout << rok - lok - 1 << endl;
}

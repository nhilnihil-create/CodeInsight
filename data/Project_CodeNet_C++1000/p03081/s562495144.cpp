#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<char, char>;

void leave(string message) {
    cout << message << endl;
    exit(0);
}

int main() {
    lint n, q;
    string s;
    cin >> n >> q >> s;

    vector<P> td(q);
    for(int i=0; i<q; i++) cin >> td[i].first >> td[i].second;

    // -1: NG_LEFT, 0: NG_RIGHT, 1: OK
    auto simulate = [&](int idx) {
        for(auto e : td) {
            char t = e.first, d = e.second;
            if(s[idx] == t) {
                idx += (d == 'L' ? -1 : +1);
                if(idx < 0) return -1;
                if(idx > n-1) return 0;
            }
        }
        return 1;
    };

    if(simulate(0) == 0) leave("0");
    if(simulate(n-1) == -1) leave("0");

    int ng, ok;
    ng = -1, ok = n;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        (simulate(mid) == -1 ? ng : ok) = mid;
    }
    int left = ok;

    if(simulate(left) == 0) leave("0");
    ng = n;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        (simulate(mid) == 1? ok : ng) = mid;
    }
    int right = ng;

    cout << right - left << endl;
}
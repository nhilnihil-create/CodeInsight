#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int H, W;
    string buf;
    vector<string> s;

    cin >> H >> W;

    string padding = "";
    rep(i, W+2) {
        padding = padding +'.';
    }
    s.push_back(padding);
    rep(i, H) {
        cin >> buf;
        s.push_back('.'+buf+'.');
    }
    s.push_back(padding);

    rep(i, H) {
        rep(j, W) {
            if (s[i+1][j+1] == '#') {
                if ((s[i][j+1] == '#')
                || (s[i+1][j] == '#')
                || (s[i+2][j+1] == '#')
                || (s[i+1][j+2] == '#')) 
                {
                    continue;
                }

                else {cout << "No" << endl; return 0;}
                
            }
        }
    }

    cout << "Yes" << endl;

}

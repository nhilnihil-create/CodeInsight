#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);

    rep(i, h){
        cin >> s[i];
    }

    ll dx[] = {-1, 0, 1, 0};
    ll dy[] = {0, 1, 0, -1};

    rep(i, h){
        rep(j, w){
            if (s[i][j] == '.'){
                continue;
            }
            bool flg = true;
            rep(k, 4){
                ll y = i+dy[k];
                ll x = j+dx[k];
                if (x < 0 || x >= w || y < 0 || y >= h){
                    continue;
                }
                if (s[y][x] == '#'){
                    flg = false;
                    break;
                }
            }
            if (flg){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}

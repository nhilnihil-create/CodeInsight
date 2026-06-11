#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }

    ll x[] = {-1, 0, 1, -1, 1, -1, 0, 1 };
    ll y[] = {1, 1, 1, 0, 0, -1, -1, -1 };

    rep(i, h){
        rep(j, w){
            if (s[i][j] == '.'){
                ll cnt = 0;
                rep(ii, 8){
                    ll xi = j + x[ii];
                    ll yi = i + y[ii];
                    if ( xi < 0 || xi >= w || yi < 0 || yi >= h){
                        continue;
                    }
                    if(s[yi][xi] == '#'){
                        cnt++;
                    }
                }
                s[i][j] = to_string(cnt)[0];
            }
        }
    }

    rep(i, h){
        cout << s[i] << endl;
    }


    return 0;
}

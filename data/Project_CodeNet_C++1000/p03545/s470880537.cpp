#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, pair<ll,ll>>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

ll ans;
ll a[4], op[3];
char ope[3], b[4];

int main() {
    rep(i,4) cin >> b[i];
    rep(i,4) a[i] = b[i]-'0';

    rep(i,8){
        rep(j,3){
            op[j] = (i>>j)&1;
        }

        ans = a[0];
        rep(j,3){
            if (op[j] == 0){
                ans-=a[j+1];
                ope[j] = '-';
            }
            else {
                ans+=a[j+1];
                ope[j] = '+';
            }
        }

        if (ans == 7){
            cout << a[0];
            rep(j,3){
                cout << ope[j] << a[j+1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }

    return 0;
}
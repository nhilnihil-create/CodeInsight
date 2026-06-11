#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    string s;
    cin >> s;
    string keyence = "keyence";

    if (s == keyence){
        puts("YES");
        return 0;
    }

    ll n = s.size();
    rep(i, n){
        rep(j, n){
            string tmp;
            rep(k, n){
                if (i <= k && k <= j){
                    continue;
                }
                tmp.push_back(s[k]);
            }
            if (tmp == keyence){
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");
    return 0;
}

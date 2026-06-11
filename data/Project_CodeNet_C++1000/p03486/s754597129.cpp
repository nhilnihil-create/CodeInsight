#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{

    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    ll n = min(s.size(), t.size());
    rep(i, n){
        ll s_n = '0' + s[i];
        ll t_n = '0' + t[i];
        if (s_n > t_n){
            puts("No");
            return 0;
        }else if (s_n < t_n){
            puts("Yes");
            return 0;
        }
    }

    if (s.size() < t.size()){
        puts("Yes");
    }else{
        puts("No");
    }

    return 0;
}

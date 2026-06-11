#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    for(ll i = 0;i < n;i++){
        cin >> s[i];
    }

    ll a, b, ba;
    a = b = ba = 0;
    ll ans = 0;

    for(ll i = 0;i < n;i++){
        if(s[i][0] == 'B' && s[i][(ll)s[i].size() - 1] == 'A'){
            ba++;
        }
        else if(s[i][0] == 'B'){
            b++;
        }
        else if(s[i][(ll)s[i].size() - 1] == 'A'){
            a++;
        }
        for(ll j = 0;j < (ll)s[i].size() - 1;j++){
            if(s[i][j] == 'A' && s[i][j + 1] == 'B'){
                ans++;
            }
        }
    }

    if(ba >= 1){
        ans += ba - 1;
        if(a >= 1){
            ans++;
            a--;
        }
        if(b >= 1){
            ans++;
            b--;
        }
    }

    ans += min(a, b);

    cout << ans;

    return 0;
}

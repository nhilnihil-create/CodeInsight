#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll powk(ll a, ll n = 2){
    ll r = 1;
    for(ll i = 0;i < n;i++){
        r *= a;
    }

    return r;
}

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> w(n + 1), e(n + 1);

    for(ll i = 0;i < n;i++){
        if(s[i] == 'W'){
            if(i != 0){
                w[i + 1] = w[i];
            }
            w[i + 1]++;
        }
        else if(i != 0){
            w[i + 1] = w[i];
        }
        if(s[n - i - 1] == 'E'){
            if(i != 0){
                e[n - i - 1] = e[n - i];
            }
            e[n - i - 1]++;
        }
        else if(i != 0){
            e[n - i - 1] = e[n - i];
        }
    }

    ll ans = w[0] + e[0];

    for(ll i = 0;i < n + 1;i++){
        ans = min(ans, w[i] + e[i]);
    }

    cout << ans;

    return 0;
}
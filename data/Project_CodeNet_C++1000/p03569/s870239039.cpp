#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll powk(ll a, ll n){
    ll r = 1;
    for(ll i = 0;i < n;i++){
        r *= a;
    }

    return r;
}

int main()
{
    string s;
    cin >> s;
    string t;
    for(ll i = 0;i < s.size();i++){
        if(s[i] != 'x'){
            t.push_back(s[i]);
        }
    }
    for(ll i = 0;i < t.size() / 2;i++){
        if(t[i] != t[t.size() - 1 -i]){
            cout << -1;
            return 0;
        }
    }
    ll r = 0, l = s.size() - 1, ans = 0;
    while(r != l && r < l){
        if(s[r] == s[l]){
            r++;
            l--;
        }
        else if(s[r] == 'x'){
            ans++;
            r++;
        }
        else{
            ans++;
            l--;
        }
    }

    cout << ans;

    return 0;
}
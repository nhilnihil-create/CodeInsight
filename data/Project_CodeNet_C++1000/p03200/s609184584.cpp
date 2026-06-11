#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    ll ans = 0;
    for(i = 0;i < n;++i){
        if(s.at(i) == 'W'){
            ans += i;
            ++cnt;
        }
    }
    for(i = 0;i < cnt;++i){
        ans -= i;
    }
    cout << ans << endl;

    return 0;
}
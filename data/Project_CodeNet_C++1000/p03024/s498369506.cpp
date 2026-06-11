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
    ll k = s.size();
    ll ans = 0;
    for(i = 0;i < k;++i){
        if(s.at(i) == 'o') ++ans;
    }
    ans += 15 - k;
    if(ans > 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
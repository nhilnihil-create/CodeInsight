#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q);
    vector<char> d(q);
    rep(i,q){
        cin >> t[i] >> d[i];
    }
    ll sup = -1;
    ll inf = n;
    while(inf - sup > 1){
        ll mid = (sup + inf)/2;
        ll ind = mid;
        rep(i,q){
            if(s[ind] == t[i]){
                if(d[i] == 'L') --ind;
                else ++ind;
            }
            if(ind == -1 || ind == n) break;
        }
        if(ind == -1) sup = mid;
        else inf = mid;
    }
    ll l = sup;
    sup = -1;   inf = n;
    while(inf - sup > 1){
        ll mid = (sup + inf)/2;
        ll ind = mid;
        rep(i,q){
            if(s[ind] == t[i]){
                if(d[i] == 'L') --ind;
                else ++ind;
            }
            if(ind == -1 || ind == n) break;
        }
        if(ind == n) inf = mid;
        else sup = mid;
    }
    ll r = inf;
    if(r <= l) cout << n - n << endl;
    else cout << n - (l + 1 + n - r) << endl;

    return 0;
}
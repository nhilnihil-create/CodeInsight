#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    sort(all(a));
    vector<pair<ll,ll>> aa;
    ll tmp = a.front();
    ll num = 1;
    for(i = 1;i < n;++i){
        if(a.at(i) == tmp) ++ num;
        else{
            aa.emplace_back(tmp, num);
            tmp = a.at(i);
            num = 1;
        }
    }
    aa.emplace_back(tmp, num);
    n = aa.size();
    i = n-1;
    ll ans = 0;
    while(i >= 0){
        if(aa.at(i).second == 0){
            --i;
            continue;
        }
        ll now = aa.at(i).first;
        --aa.at(i).second;
        tmp = now;
        num = 0;
        while(tmp != 1){
            tmp >>= 1;
            ++num;
        }
        rep(j,num+1) tmp <<= 1;
        ll obj = tmp-now;
        ll ind = lower_bound(all(aa), make_pair(obj,0ll)) - aa.begin();
        if(aa.at(ind).first != obj){
            --i;
            continue;
        }else{
            if(aa.at(ind).second == 0){
                --i;
                continue;
            }else{
                --aa.at(ind).second;
                ++ans;
            }
        }
        if(aa.at(i).second == 0) --i;
    }
    cout << ans << endl;
    return 0;
}
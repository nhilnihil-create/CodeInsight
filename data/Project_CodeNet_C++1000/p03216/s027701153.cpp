#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
ll n,q;
string s;
ll cnt[1000006];
ll cnt2[1000006];
ll dpd[1000006];
ll gt(ll x)
{
        if(x < 0) return 0;
        return dpd[x];
}
ll gt2(ll x)
{
        if(x < 0) return cnt2[0];
        return cnt2[x];
}
int main()
{
        cin >> n >> s >> q;
        for(ll i=n-1;i>=0;i--){
                cnt[i] = cnt[i+1];
                cnt2[i] = cnt2[i+1];
                cnt2[i] += (s[i] == 'D');
                cnt[i] += (s[i] == 'M');
        }
        for(ll i=0;i<n;i++){
                dpd[i] += dpd[i-1];
                if(s[i] == 'D') dpd[i] += cnt[i+1];
        }
        while(q--){
                ll ans = 0;
                ll k;
                cin >> k;
                for(ll i=0;i<n;i++) {
                        if(s[i] != 'C') continue;
                        ans += gt(i-2) - gt(i-k) - cnt[i+1]*(gt2(i-k+1) - gt2(i-1));
                }
                cout << ans << "\n";
        }
        return 0;
}

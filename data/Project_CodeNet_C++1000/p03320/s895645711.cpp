#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
ll K;
ll ds(ll x)
{
        ll ret = 0;
        while(x)
        {
                ret += x%10;
                x = x / 10;
        }
        return ret;
}
ld gets(ll x)
{
        ld ay = ds(x);
        ay = ((ld)(1.0*x) / (ay));
        return ay;
}
vector<ll> v , X;
int main()
{
        //cout<<setprecision(12) << fixed;
        cin >> K;
        v.pb(999999999999999LL);
        ll rm = 1;
        for(ll i=0;i<=16;i++){
                X.pb(rm);
                rm = rm*10LL;
        }
        ll cur = v.back();
        while(cur != 1) {

                ll nxt = 0;
                for(auto i : X) {
                        nxt = cur - i;
                        if(nxt <= 0) break;
                        if(gets(nxt) > gets(cur)) {
                                continue;
                        }
                        v.pb(nxt);
                                cur = nxt;
                                break;
                }
        }
        reverse(v.begin() , v.end());
        for(ll i=0;i<K;i++) cout << v[i] << "\n";
        return 0;
}

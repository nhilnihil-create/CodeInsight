#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
const ll INF = 1LL<<58;
int main()
{
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s(a+2),t(b+2);
    rep(i,a)cin >> s[i+1];
    rep(i,b)cin >> t[i+1];
    s[0] = t[0] = -INF;
    s[a+1] = t[b+1] = INF;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    vector<ll> p(q);
    rep(i,q){
        ll x;
        cin >> x;
        ll ans = INF;
        ll al = lower_bound(s.begin(),s.end(),x)-s.begin();
        ll bl  = lower_bound(t.begin(),t.end(),x) -t.begin();
        ll af = upper_bound(s.begin(),s.end(),x) - s.begin()-1;
        ll bf = upper_bound(t.begin(),t.end(),x)- t.begin()-1;
        ans = min(ans,abs(s[af]-x)+abs(s[af]-t[bf]));
        ans = min(ans,abs(s[af]-x)+abs(s[af]-t[bl]));
        ans = min(ans,abs(s[al]-x)+abs(s[al]-t[bl]));
        ans = min(ans,abs(s[al]-x)+abs(s[al]-t[bf]));
        ans = min(ans,abs(t[bf]-x)+abs(s[af]-t[bf]));
        ans = min(ans,abs(t[bf]-x)+abs(s[al]-t[bf]));
        ans = min(ans,abs(t[bl]-x)+abs(s[af]-t[bl]));
        ans = min(ans,abs(t[bl]-x)+abs(s[al]-t[bl]));

       p[i] = ans;



    }
    rep(i,q)cout << p[i] << endl;

    return 0;
}
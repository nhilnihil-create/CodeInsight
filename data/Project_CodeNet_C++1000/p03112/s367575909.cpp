#include<bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;
typedef pair<int,int> pi;
typedef long long int ll;

const int N = (int)2e5+5;

ll closest(vector<ll>& s, ll& x) {
    int ret = lower_bound(s.begin(),s.end(),x) - s.begin();
    if(ret == s.size()) ret--;
    else if(ret>0) {
       if(abs(s[ret-1]-x)<abs(s[ret]-x)) {
        ret--;
       }
    }
    return s[ret];
}
ll solve(vector<ll>& s, vector<ll>& t, ll& x) {
    ll ret = 1e18;
    for(int i=lower_bound(s.begin(),s.end(),x)-s.begin(),j=i-10;j<i+10;j++) {
        if(j<0 || j>=s.size()) continue;
        ll p1 = s[j];
        ll p2 = closest(t,p1);
        ret = min(ret,abs(x-p1) + abs(p1-p2));
    }
    for(int i=lower_bound(t.begin(),t.end(),x)-t.begin(),j=i-10;j<i+10;j++) {
        if(j<0 || j>=t.size()) continue;
        ll p1 = t[j];
        ll p2 = closest(s,p1);
        ret = min(ret,abs(x-p1) + abs(p1-p2));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a), t(b);
    for(int i=0;i<a;i++) {
        cin>>s[i];
    }
    for(int i=0;i<b;i++) {
        cin>>t[i];
    }
    while(q--) {
        ll x;
        cin>>x;
        cout<<solve(s,t,x)<<"\n";
    }
}

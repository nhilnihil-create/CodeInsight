#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll MX = 100000000000;



int main(){
    int a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a+2),t(b+2);
    s[0] = -1*MX;
    t[0] = -1*MX;
    s[a+1] = MX;
    t[b+1] = MX;
    rep(i,a) cin>>s[i+1];
    rep(i,b) cin>>t[i+1];

    ll x=0;
    ll sa,sb,ta,tb;
    vector<ll>::iterator itr;
    rep(i,q){
        ll ans = MX;

        cin>>x;
        itr = lower_bound(s.begin(),s.end(),x);
        sb = *itr;
        --itr;
        sa = *itr;

        itr = lower_bound(t.begin(),t.end(),x);
        tb = *itr;
        --itr;
        ta = *itr;


        ans = min({ans,x - min(sa,ta),max(sb,tb)-x});
        ans = min({ans,tb - sa + min(x - sa,tb - x),sb - ta + min(x - ta,sb - x)});

        cout << ans<< endl;
    }
}



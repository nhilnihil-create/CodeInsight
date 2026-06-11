#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    ll a,b,q;
    cin>>a>>b>>q;
    vll s;
    vll t;
    s.push_back(-100000000000000);
    t.push_back(-100000000000000);
    rep(i,a){
        ll ss;
        cin>>ss;
        s.push_back(ss);
    }
    rep(i,b){
        ll tt;
        cin>>tt;
        t.push_back(tt);
    }
    s.push_back(10000000000000);
    t.push_back(10000000000000);
    rep(i,q){
        ll x;
        cin>>x;
      
        auto indexs=s.begin();
        auto indext=t.begin();


        auto index1=lower_bound(all(s),x);
        ll x1=s[index1-s.begin()];
        ll x2=s[index1-1-s.begin()];
        auto index12=lower_bound(all(t),x1);
        auto index22=lower_bound(all(t),x2);
        ll ans12=min(abs(x1-t[index12-indext]),abs(x1-t[index12-1-indext]));
        ll ans22=min(abs(x2-t[index22-indext]),abs(x2-t[index22-1-indext]));

        ll ans1=min(abs(x-x1)+ans12,abs(x-x2)+ans22);

        auto index2=lower_bound(all(t),x);
        ll x3=t[index2-indext];
        ll x4=t[index2-1-indext];
        auto index33=lower_bound(all(s),x3);
        auto index44=lower_bound(all(s),x4);
        ll ans33=min(abs(x3-s[index33-indexs]),abs(x3-s[index33-1-indexs]));
        ll ans44=min(abs(x4-s[index44-indexs]),abs(x4-s[index44-1-indexs]));

        ll ans2=min(abs(x-x3)+ans33,abs(x-x4)+ans44);

        ll ans=min(ans1,ans2);
        cout<<ans<<endl;

    }


    return 0;
}
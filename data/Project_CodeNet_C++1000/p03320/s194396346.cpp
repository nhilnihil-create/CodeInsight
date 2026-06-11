#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define debug(x) cerr<<#x<<": "<<x<<endl
typedef long long ll;

int S(ll x){
    string str = to_string(x);
    int res = 0;
    for(char c : str){
        res += c-'0';
    }
    return res;
}

using P = pair<double,pair<ll,ll>>;

int main(void){
    int k;
    cin>>k;
    vector<P> v;
    ll nine = 0;
    rep(d,16){
        rep(i,400000){
            ll a = i*(nine+1);
            if(nine >= LLONG_MAX - a) break;
            ll x = nine + a;
            ll sx = S(x);
            v.push_back({(double)x/sx, {x,sx}});
        }
        nine = nine*10+9;
    }
    sort(all(v));
    ll max = 0;
    int cnt = 0;
    for(P p : v){
        ll x = p.second.first;
        if(max >= x) continue;
        max = x;
        cout<<x<<endl;
        cnt++;
        if(cnt == k)break;
    }

    return 0;
}

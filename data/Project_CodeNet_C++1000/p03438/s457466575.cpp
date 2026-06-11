#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin>>n;
    vector<ll> as(n);
    rep(i, n) cin>>as[i];
    vector<ll> bs(n);
    rep(i, n) cin>>bs[i];

    ll m = 0;
    ll cnt = 0;
    rep(i, n) {
        ll d = bs[i] - as[i];
        m += d;
        if (d < 0) cnt += -d;
        if (d > 0 && d % 2 == 1) cnt++;
    }
    if (m < 0) {
        cout<<"No"<<endl;
        return 0;
    }
    if (cnt > m) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
}
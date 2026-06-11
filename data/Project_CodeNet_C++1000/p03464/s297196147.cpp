#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
bool isOkmx(ll a,vector<int> v){
    
    rep(i,v.size()){
        a /= v[i];
        a *= v[i];
    }
    return a >= 2;
}
bool isOkmin(ll a,vector<int> v){
    rep(i,v.size()){
        a /= v[i];
        a *= v[i];
    }
    return a <= 2;
}
int main()
{
    int k;
    cin >> k;
    vector<int> a(k);
    rep(i,k){
        cin >> a[i];
    }
    ll ok = 1e+18;
    ll ng = 1;
    ll lx = 0, rx = 0;
    while (abs(ok - ng)>1)
    {
        ll mid = (ng+ok)/2;
        if(isOkmx(mid,a)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    lx = ok;
    ok = 1;
    ng = 1e+18;
    while (abs(ok - ng)>1)
    {
        ll mid = (ng + ok) / 2;
        if (isOkmin(mid, a))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    rx = ok;
    if(lx > rx){
        cout << -1 << endl;
    }else{
        cout << lx << " " << rx << endl;
    }
}
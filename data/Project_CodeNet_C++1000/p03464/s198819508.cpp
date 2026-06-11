#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
bool isOkmin(ll num,vector<int> v){
    rep(i,v.size()){
        num /= v[i];
        num *= v[i];
    }
    return num >= 2;
}
bool isOkmx(ll num,vector<int> v){
    rep(i,v.size()){
        num /= v[i];
        num *= v[i];
    }
    return num <= 2;
}
int main()
{
    int k;
    cin >> k;
    vector<int> a(k);
    rep(i,k){
        cin >> a[i];
    }
    ll l, r;
    ll ok = 1e18;
    ll ng = 1;
    while(abs(ok-ng) > 1){
        ll mid =(ok+ng)/2;
        if(isOkmin(mid, a)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    l = ok;
    ok = 1;
    ng = 1e18;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (isOkmx(mid, a))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    r = ok;
    if(l<=r){
        cout << l << " " << r;
    }else{
        cout << -1 << endl;
    }
}
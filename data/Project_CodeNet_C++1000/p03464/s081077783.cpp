#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll k;
    cin >> k;
    vector<ll> a(k);
    for(i = 0;i < k;++i){
        cin >> a.at(i);
    }
    if(a.back() != 2){
        cout << -1 << endl;
        return 0;
    }
    ll mi = 2, ma = 2;
    for(i = 1;i < k;++i){
        ll tmpmi = mi;
        ll tmpma = ma + a.at(k-1-i+1) - 1;
        if(tmpmi%a.at(k-1-i) && tmpma%a.at(k-1-i)){
            if(tmpmi/a.at(k-1-i) == tmpma/a.at(k-1-i)){
                cout << -1 << endl;
                return 0;
            }
        }
        if(tmpmi%a.at(k-1-i) == 0){
            mi = tmpmi;
        }else{
            mi = (tmpmi + a.at(k-1-i))/a.at(k-1-i)*a.at(k-1-i);
        }
        ma = tmpma/a.at(k-1-i)*a.at(k-1-i);
    }
    ma = ma + a.at(0)-1;
    cout << mi << endl;
    cout << ma << endl;

    return 0;
}
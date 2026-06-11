#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll m,k;
    cin >> m >> k;
    if(m == 0){
        if(k == 0) cout << "0 0" << endl;
        else cout << -1 << endl;
        return 0;
    }else if(m == 1){
        if(k == 0) cout << "0 0 1 1" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(k >= (1ll << m)){
        cout << -1 << endl;
        return 0;
    }
    for(i = 0;i < (1ll << m);++i){
        if(i != k) cout << i << endl;
    }
    cout << k << endl;
    for(i = (1ll << m) -1;i >= 0;--i){
        if(i != k) cout << i << endl;
    }
    cout << k << endl;

    return 0;
}
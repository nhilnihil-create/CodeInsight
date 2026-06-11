#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    if(a.at(0)){
        cout << -1 << endl;
        return 0;
    }
    ll tmp = a.back();
    if(tmp > n-1){
        cout << -1 << endl;
        return 0;
    }
    ll ans = tmp;
    for(i = n-2;i >= 0;--i){
        if(a.at(i) < tmp){
            if(a.at(i) != tmp-1){
                cout << -1 << endl;
                return 0;
            }else{
                tmp = a.at(i);
                continue;
            }
        }else{
            if(a.at(i) > i){
                cout << -1 << endl;
                return 0;
            }else{
                tmp = a.at(i);
                ans += tmp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
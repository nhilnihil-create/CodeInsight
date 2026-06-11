#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    for(i = 0;i < n;++i){
        cin >> b.at(i);
    }
    ll tmp = 0;
    for(i = 0;i < n;++i){
        if(a.at(i) == b.at(i)) continue;
        else if(a.at(i) > b.at(i)){
            tmp += 2*(a.at(i) - b.at(i));
        }else{
            tmp -= (b.at(i) - a.at(i))/2*2;
        }
    }
    if(tmp <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
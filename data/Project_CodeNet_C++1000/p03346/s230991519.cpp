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
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<ll> b(n);
    for(i = 0;i < n;++i){
        b.at(a.at(i)-1) = i;
    }
    ll maxlen = 0;
    ll l = 1;
    for(i = 0;i < n-1;++i){
        if(b.at(i) < b.at(i+1)) ++l;
        else{
            maxlen = max(maxlen, l);
            l = 1;
        }
    }
    maxlen = max(maxlen, l);
    cout << n - maxlen << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,z,w;
    cin >> n >> z >> w;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    if(n == 1) cout << abs(a.at(0) - w);
    else cout << max(abs(a.at(n-1) - w), abs(a.at(n-2) - a.at(n-1))) << endl;

    return 0;
}
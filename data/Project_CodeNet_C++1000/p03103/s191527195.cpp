#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    ll t=0;
    for(int i=0; i<n && m>0; ++i){
        t += a[i].first * ((a[i].second > m)?m:a[i].second);
        m -= a[i].second;
    }
    cout << t;
}

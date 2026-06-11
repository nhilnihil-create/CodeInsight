#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(pair<ll, ll> x, pair<ll, ll> y){
    return x.first > y.first;
}
int main()
{
    ll n, m;
    cin>>n>>m;
    ll a[n];
    for (int i=0; i<n; i++)cin>>a[i];
    vector<pair<ll, ll> > b(m);
    for (int i=0; i<m; i++){
        ll x, y;
        cin>>x>>y;
        b[i] = {y, x};
    }
    sort(a, a+n);
    sort(b.begin(), b.end(), compare );
    // for (int i=0; i<m; i++){
    //     cout<<b[i].first<<" "<<b[i].second<<endl;
    // }
    int s = 0;
    int idx = 0;
    while(s<n && idx<m && b[idx].first > a[s]){
        ll inc = b[idx].second;
        while(s<n && b[idx].first > a[s] && inc > 0){
            a[s] = b[idx].first;
            s++;
            inc--;
        }
        idx++;
    }
    ll sum = 0;
    for (int i=0; i<n; i++)sum+= a[i];
    cout<<sum<<endl;
}
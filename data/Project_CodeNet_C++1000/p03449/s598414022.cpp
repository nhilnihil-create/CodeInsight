#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>a(n,0);
    vector<ll>b(n,0);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    reverse(all(b));
    for (int i = 0; i < n-1; ++i) {
        a[i + 1] += a[i];
        b[i + 1] += b[i];
    }
    reverse(all(b));
    ll ans=0;
    for (int i = 0; i < n ; ++i) {
        ans=max(ans,a[i]+b[i]);
    }
    cout <<ans<<endl;
    return 0;
}


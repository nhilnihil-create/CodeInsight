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
    vector<ll>l(n+1,0);
    vector<ll>r(n+1,0);
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        l[i+1]=__gcd(l[i],a[i]);
    }
    reverse(all(a));
    for (int i = 0; i < n; ++i) {
        r[i+1]=__gcd(r[i],a[i]);
    }
    reverse(all(r));
    ll ans=0;
    for (int i = 1; i <=n; ++i) {
        ans=max(ans,__gcd(r[i],l[i-1]));
//        cout<<l[i-1]<<" "<<r[i]<<endl;
    }
    cout <<ans <<endl;
    return 0;
}

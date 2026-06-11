#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    ll n,k;cin >>n>>k;
    k--;
    vector<ll>h(n);
    for (int i = 0; i < n; ++i) {
        cin >>h[i];
    }
    sort(all(h));
    ll ans=INF;
    for (int i = 0; i < n; ++i) {
        if(i+k>=n)break;
        ll tmp=h[i+k]-h[i];
        ans=min(ans,tmp);
    }
    cout <<ans <<endl;
    return 0;
}


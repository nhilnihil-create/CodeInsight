#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    ll n;cin >>n;
    vector<ll>q(n);
    for (int i = 0; i < n; ++i) {
        ll p;cin >>p;
        p--;
        q[p]=i;
    }
    ll now=1;
    ll ans=1;
    for (int i = 0; i < n-1; ++i) {
        if(q[i]<q[i+1])now++;
        else {
            ans=max(ans,now);
            now=1;
        }
    }
    if(now!=1)ans=max(ans,now);
    cout <<n-ans<<endl;
    return 0;
}


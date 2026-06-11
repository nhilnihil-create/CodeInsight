#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
   ll n,k;cin >>n>>k;
   vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    vector<ll>cnt(50,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 50; ++j) {
            if((a[i]>>j)&1LL)cnt[j]++;
        }
    }
    ll now=0;
    ll ans=0;
    for (int i = 49; i>=0;--i) {
        if(now+((1LL)<<i)<=k) {
            if (cnt[i] < n - cnt[i]) {
                now += ((1LL) << i);
                ans += ((1LL) << i) * (n - cnt[i]);
            } else {
                ans += ((1LL) << i) * cnt[i];
            }
        }
        else {
            ans += ((1LL) << i) * cnt[i];
        }
    }
    cout <<ans <<endl;
}

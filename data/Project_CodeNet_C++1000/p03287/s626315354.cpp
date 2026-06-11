#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n;cin >> n;
    ll m;cin >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<ll,ll> mp;
    mp[0]++;
    for(int i=0;i<n;i++){
        a[i]%=m;
    }
    vector<ll> sum(n+1);
    for(int i=0;i<n;i++){
        sum[i+1]+=(sum[i]+a[i])%m;
        sum[i+1]%=m;
    }
    for(int i=1;i<=n;i++){
        mp[sum[i]]++;
    }
    ll ans=0;
    for(auto p:mp){
        ans+=p.second*(p.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}
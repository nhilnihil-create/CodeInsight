#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    ll n,k;cin>>n>>k;
    vector<ll>v(n);
    for (int i = 0; i < n; ++i) {
        cin >>v[i];
    }
    vector<ll>ml;
    ll ans=0;
    for (int l = 0; l <=k; ++l) {
        for (int r = 0; r <= k-l; ++r) {
            if(l+r>n)continue;
            ll d=k-r-l;
            ll now=0;
            vector<ll>s;//取り出す集合
            for (int i = 0; i < l; ++i) {
                now+=v[i];
                s.push_back(v[i]);
            }
            for (int j = n-r; j <n ; ++j) {
                now+=v[j];
                s.push_back(v[j]);
            }
            sort(all(s));
            for (int m = 0; m < d; ++m) {
                if(s.size()<=m)break;
                if(s[m]>=0)break;
                now-=s[m];
            }
            ans=max(ans,now);
        }
    }
    cout << ans << endl;
    return 0;
}
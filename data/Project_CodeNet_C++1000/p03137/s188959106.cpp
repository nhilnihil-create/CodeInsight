#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,m;cin >>n>>m;
    vector<ll>x(m);
    for (int i = 0; i < m; ++i) {
        cin >>x[i];
    }
    sort(all(x));
    vector<ll>d;
    ll ans=0;
    for (int i = 0; i < m- 1; ++i) {
        d.push_back(x[i + 1] - x[i]);
    }
    sort(all(d));
    ll s=m-n;
    for (int j = 0; j <s; ++j) {
        ans+=d[j];
    }
    cout <<ans <<endl;
    return 0;
}
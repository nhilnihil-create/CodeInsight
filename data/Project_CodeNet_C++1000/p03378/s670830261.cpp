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
    ll n,m,x;cin >>n>>m>>x;
    vector<ll>a(m);ll cnt=0;
    ll ans=0;
    for (int i = 0; i < m; ++i) {
        cin >>a[i];
        if(a[i]>x)cnt++;
        else ans++;
    }
    cnt=min(ans,cnt);
    cout <<cnt<<endl;
    return 0;
}
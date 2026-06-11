#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,m,x,y;cin >>n>>m>>x>>y;
    vector<ll>a(n);
    vector<ll>b(m);
    ll mint=INF,mx=-INF;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        mx=max(a[i],mx);
    }
    for (int i = 0; i < m; ++i) {
        cin >>b[i];
        mint=min(mint,b[i]);
    }
    bool flg=false;
//    cout <<mint<<" "<<mx<<endl;
    for (ll z = x+1; z <=y; ++z) {
        if(z<=mint&&z>mx)flg=true;
    }
    if(!flg)puts("War");
    if(flg)puts("No War");
    return 0;
}
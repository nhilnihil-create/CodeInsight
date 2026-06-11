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
   ll n,h;cin >>n>>h;
   vector<ll>a(n);
   vector<ll>b(n);
   vector<ll>c;
   ll mx=-1;
    for (int i = 0; i < n; ++i) {
        cin >>a[i]>>b[i];
        mx=max(mx,a[i]);
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    sort(all(c));
    reverse(all(c));
    ll j=0;
    ll ans=0;
    while(1){
        if(c[j]>mx){
            h-=c[j];
            ans++;
            j++;
        }
        else break;
        if(h<=0)break;
    }
    if(h>0){
        ans+=(h-1)/mx+1;
    }
    cout <<ans <<endl;
}

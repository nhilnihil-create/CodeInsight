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
    ll n,k;cin >>n>>k;
    ll a;
    vector<ll>cnt(50,0);
    for (int i = 0; i < n; ++i) {
        cin >>a;
        for (int j= 0; j< 50; ++j) {
            if((a>>j)&1LL){
                cnt[j]++;
            }
        }
    }
    ll ans=0;
    vector<ll>f(50,1);
    for (int l = 0; l < 49; ++l) {
        f[l+1]=f[l]*2;
    }
//    for (int i = 0; i < 5; ++i) {
//        cout <<cnt[i]<<endl;
//    }
    ll num=0;
    for (int i = 49; i>=0; --i) {
        if(num+f[i]<=k){
            if(cnt[i]<n-cnt[i]){
                num+=f[i];
                ans+=f[i]*(n-cnt[i]);
            }
            else {
                ans+=f[i]*cnt[i];
            }
        }
        else  {
            ans+=f[i]*cnt[i];
        }
    }
    cout <<ans <<endl;
    return 0;
}
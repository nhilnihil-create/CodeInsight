#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    vector<tuple<string,ll,ll>>a(n);
    rep(0,i,n){
        string s;
        ll p;
        cin>>s>>p;
        a[i]={s,-p,i};
    }
    sort(a.begin(),a.end());
    rep(0,i,n)cout<<get<2>(a[i])+1<<endl;
}

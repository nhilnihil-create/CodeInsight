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
    ll n;cin>>n;
    ll suma=0,sumb=0;
    ll needa=0,needb=0;
    vector<ll>a(n),b(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];suma+=a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >>b[i];sumb+=b[i];
    }
    for (int j = 0; j < n; ++j) {
        ll d=a[j]-b[j];
        if(d>0)needb+=d;
        ll id=-d;
        if(id>0){
            needa+=(id-1)/2+1;
        }
    }
    bool flg=true;//yesorno
    ll opt=sumb-suma;
    if(opt<max(needa,needb))flg=false;
    if(flg)puts("Yes");
    else puts("No");
   // cout <<suma<<" "<<sumb<<" "<<opt<<" "<<needa<<" "<<needb<<" "<<endl;
    return 0;
}
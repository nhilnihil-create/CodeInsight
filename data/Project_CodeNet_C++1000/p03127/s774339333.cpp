#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

//最大公約数を求める関数
ll gcd(ll a,ll b){
    int c,d,e;
    c=max(a,b);
    d=min(a,b);
    while(1){
        c=c%d;
        if(c==0){
            break;
        }
        e=d;
        d=c;
        c=e;
    }
    return d;
}

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    ll ans=a[0];
    rep(i,n-1){
        ans=gcd(ans,a[i+1]);
    }

    cout << ans << endl;

    

    return 0;
}
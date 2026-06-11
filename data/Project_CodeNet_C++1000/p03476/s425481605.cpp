#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    //エラトステネスのふるい
    int max=1e5+1;
    vector<ll> isprime(max,1);
    isprime[0]=isprime[1]=0;
    for(int i=2;i<max;i++){
        if(!isprime[i]) continue;
        //素数じゃないやつに0入れる
        for(int j=i*2;j<max;j+=i) isprime[j]=0;
    }

    //like2017
    vector<ll> a(max,0);
    rep(i,max){
        if(isprime[i]&&isprime[(i+1)/2]) a[i]=1;
    }

    //累積和
    vector<ll> s(max+1,0);
    rep(i,max) s[i+1]=s[i]+a[i];

    //クエリ処理
    ll q; cin>>q;
    rep(i,q){
        ll l,r; cin>>l>>r;
        cout<<s[r+1]-s[l]<<endl;
    }

    return 0;
}
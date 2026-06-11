#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;


int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> x(N) , y(N), z(N);
    rep(i,N) cin >> x[i] >> y[i] >> z[i];
    ll ans=0;
    rep(bit,(1<<3)){
        vector<ll> res(N,0); 
        rep(i,N){
            if(bit&(1<<0))res[i]+=x[i];//1番目のビットが立っているか
            else res[i]-=x[i];
            if(bit&(1<<1))res[i]+=y[i];//2番目のビットが立っているか
            else res[i]-=y[i];
            if(bit&(1<<2))res[i]+=z[i];//3番目のビットが立っているか
            else res[i]-=z[i];
        }
        sort(res.rbegin(),res.rend());//降順ソート
        ll tmp = 0;
        rep(i,M)tmp+=res[i];//降順になっているので配列のはじめの方からM個足していけばよい
        ans=max(ans,tmp);//今までのやつのうち最大のものをとる
    }
    cout << ans << endl;
}

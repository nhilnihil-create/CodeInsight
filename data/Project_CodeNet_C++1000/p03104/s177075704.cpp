#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll calc(ll x){ //[0,x)のxor０から数えるので
    if(x<=0)return  0;
    ll ans=0;
    for (int i = 0; i < 50; ++i) {
        ll loop=(1LL<<(i+1));//周期
        ll co=(x/loop)*(loop/2);//ループした回数＊１の数
        co+=max(0LL,(x%loop)-(loop/2));//00001111 -に注意
        if(co%2==1){
            ans+=(1LL<<i);
        }
    }
    return ans;
}

int main(){
    ll a,b;cin >>a>>b;
    ll ans=calc(b+1)^calc(a);
    cout <<ans <<endl;
    return 0;
}
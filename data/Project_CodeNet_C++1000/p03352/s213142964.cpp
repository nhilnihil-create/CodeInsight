#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005;
bool chk(ll n){
    set<ll> st;
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        ll cnt=0;
        while(n%i==0)n/=i,cnt++;
        st.insert(cnt);
    }
    if(n>1)st.insert(1);

    if(st.size()>1)return 0;
    return (*st.begin())>1;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll x;cin>>x;
    for(ll n=x;n>1;n--)if(chk(n))return cout<<n , 0;
    cout<<1;
}

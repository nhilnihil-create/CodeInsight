#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    ll N; cin>>N;
    vector<ll> A(N);
    ll m=1000000007;
    for (int i = 0; i < N; i++){
        cin>>A[i];
        m=min(A[i],m);
    }
    ll ans=1000000007;
    for (int i = 0; i < N-1; i++){
        ll x=gcd(A[i],A[i+1]);
        ans=min(ans,x);
    }
    cout<<ans<<endl;
}

#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

using namespace std;



int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(ll i = k+1;i <= n;i++) {
        int l = i - k;
        int m = n / i;
        ans += l * m;
        ans += max(0LL,n % i - (k-1));
    }
    if(k==0)ans=n*n;
    cout<<ans<<endl;
}
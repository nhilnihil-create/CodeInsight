#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    ll d;
    if(n%2==0)d=n+1;
    else d=n;
    cout<<n*(n-1)/2-n/2<<endl;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(i+j!=d)cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}
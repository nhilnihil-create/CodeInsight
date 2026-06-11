#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll ;

const ll inf = 1e12 + 17;
const int maxn = 1e5 + 10;
const int maxq = 1e2 + 10;
const int alf = 26;
const ll dlm = 1e9 + 7;
const int del = 998244353 ;
const int eps = 1e-7 ;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    ll ans = 1;
    ll n,p;
    cin>>n>>p;
    if(n==1)return cout<<p,0;
    ll y = p;
    ll ta = sqrt(y);
    for(int i=2;i<=ta;i++){
        ll re = 0;
        while(y%i==0){
            y/=i;
            re++;
        }
        ans*= pow(i,re/n);
    }
    cout<<ans;
    return 0;
}

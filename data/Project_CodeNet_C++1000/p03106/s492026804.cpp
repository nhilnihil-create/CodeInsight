#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    ll a,b,k; cin>>a>>b>>k;
    vector<ll> gcd;
    for(int i=1;i<=min(a,b);++i){
        if(a%i==0&&b%i==0) gcd.push_back(i);
    }
    reverse(gcd.begin(),gcd.end());
    cout<<gcd[k-1]<<endl;
    return 0;
} 
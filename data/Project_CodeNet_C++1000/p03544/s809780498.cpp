#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll luca(ll n){
    if(n==0) return 2;
    else if(n==1) return 1;
    else if(n>=2) return luca(n-1)+luca(n-2);
}

int main(void)
{
    ll n; cin>>n;
    vector<ll> l(n+1,0);
    l[0]=2,l[1]=1;
    for(int i=1;i<n;i++){
        l[i+1]=l[i]+l[i-1];
    }
    cout<<l[n]<<endl;
    return 0;
}

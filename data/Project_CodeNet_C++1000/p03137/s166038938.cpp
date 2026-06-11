#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, K;
    cin>>N>>K;
    vector<ll> X(K);
    for(ll i=0; i<K; i++) 
        cin>>X[i];
    sort(X.begin(), X.end());
    if(N>=K) 
        cout<<0<<endl;
    else
    {
        vector<ll> D(K-1);
        for(ll i=0; i<K-1; i++)
            D[i]=X[i+1]-X[i];
        sort(D.begin(), D.end());
        ll ans=0;
        for(ll i=0; i<K-N; i++)     
            ans+=D[i];
        cout<<ans<<endl;
    }
    return 0;
}
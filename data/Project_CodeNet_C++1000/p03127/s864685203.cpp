#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;
ll gcd(ll a,ll b){	if(b == 0)	return a;return gcd(b,a%b);}

int main()
{
    int n;
    cin>>n;

    vector<ll> A(n,0);

    for(int i=0;i<n;++i)    cin>>A[i];

    ll ans = A[0];

    for(int i=1;i<n;++i)    ans = gcd(ans, A[i]);

    cout<<ans<<'\n';

    return 0;
}
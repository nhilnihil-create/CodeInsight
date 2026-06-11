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
    ll a,b,c,d; 
    cin>>a>>b>>c>>d;
	ll x=c-a;
	ll y=d-b;
	cout<<c-y<<" "<<d+x<<" "<<a-y<<" "<<b+x<<endl;
    return 0;
}

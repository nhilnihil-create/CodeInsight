#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
typedef pair<ll,ll> ipair;
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
	ll n,i,j,p,k,m,ans=0,a,b,c;
    cin>>a>>b>>c;
    
    k =a+b+c;
    p =max(max(a,b),c);
    if((3*p)%2==k%2)
    {
        cout<<(3*p-k)/2<<endl;
    }
    else
    {
        cout<<(3*(p+1) - k)/2<<endl;
    }
    
	return 0;
}
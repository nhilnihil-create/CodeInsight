#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
ll gcd(ll a,ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n>=2*k-1)
        cout<<"YES";
    else
        cout<<"NO";
}
int main()
{
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	return(0);
}

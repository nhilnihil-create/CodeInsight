#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define INF LLONG_MAX
#define PI acos(-1)
#define MOD 1e9 + 7
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool cmp(ll a,ll b)
{
	return (a>b);
}
int main()
{
	IOS
	ll n,h,w;
	cin>>n>>h>>w;
	cout<<(n-h+1)*(n-w+1);
}
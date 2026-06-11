#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"
ll arr[100];

void lucas(ll n)
{
	arr[0]=2;
	arr[1]=1;
	for(ll i=2;i<=n;i++)arr[i]=arr[i-1]+arr[i-2];
}

int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	cin>>n;
	lucas(n);
	cout<<arr[n];

}
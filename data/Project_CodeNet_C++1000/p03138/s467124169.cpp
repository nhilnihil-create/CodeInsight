#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_N=100005;
LL a[MAX_N],n,k;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	LL x=0;
	for(int i=62;i>=0;i--)
	{
		LL cnt=0;
		for(int j=0;j<n;j++)cnt+=(bool)(a[j]&(1LL<<i));
		if(2*cnt<n && (x|(1LL<<i))<=k)x|=1LL<<i;
	}
	LL res=0;
	for(int i=0;i<n;i++)res+=x^a[i];
	cout<<res<<endl;
}
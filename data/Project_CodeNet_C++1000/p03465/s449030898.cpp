#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e7+5;
const long long inf=0x3f3f3f3f;
long long sum;
bitset<maxn>s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	long long n;
	cin>>n;
	s[0]=1;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		s|=s<<x;
		sum+=x;
	}
	for(long long i=(sum+1)>>1;;i++)
	{
		if(s[i])
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}



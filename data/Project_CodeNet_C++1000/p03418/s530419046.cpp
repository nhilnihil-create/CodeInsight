#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,k;
	cin>>n>>k;
	ll p=0;
	for(int i=k+1;i<=n;i++)
	{
		
				p += (i-k) * ((n+1)/i);
		

		if(n%i>=k && (n+1)%i!=0){
			p += n%i -k+1;
			//cout<<"yes"<<" ";
		}
		//cout<<(i-k)<<" * "<<(n+1)/i<<"\n";
		//cout<<p<<"\n";
	}
	if(k==0)
		p -= n;
	cout<<p<<"\n";
}
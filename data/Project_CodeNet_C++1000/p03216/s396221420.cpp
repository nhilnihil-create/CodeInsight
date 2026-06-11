#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,k;
string s;
int main()
{
	cin>>n>>s;
	cin>>q;
	while(q--)
	{
		ll a=0,b=0,c=0,b2=0,ans=0;
		cin>>k;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='D')a++;
			if(s[i]=='M')b++,b2+=a;
			if(s[i]=='C')ans+=b2;
			if(i>=k-1)
			{
				int fir=i-k+1;
				if(s[fir]=='D')a--,b2-=b;
				if(s[fir]=='M')b--;
			}
		}
		cout<<ans<<endl;
	} 
}
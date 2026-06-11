#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,k1;
	cin>>n>>k1;
	ll x[n];
	ll y[n];
	ll sx[n];
	ll sy[n];
	for(ll i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		sx[i]=x[i];
		sy[i]=y[i];
	}
	sort(sx,sx+n);
	sort(sy,sy+n);
	ll x1=sx[0],x2=sx[n-1];
	ll y1=sy[0],y2=sy[n-1];
	ll minar = 1LL*(x2-x1)*(y2-y1);
	//cout<<minar<<" ";
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			for(ll k=0;k<n;k++)
			{
				for(ll l=k+1;l<n;l++)
				{
					ll tx1 = sx[i],tx2=sx[j],ty1=sy[k],ty2=sy[l];
					ll area= (1LL*(tx2-tx1)*(ty2-ty1));
					ll count=0;
					for(ll m=0;m<n;m++)
					{
						if(x[m]>=tx1 && x[m]<=tx2 && y[m]>=ty1 && y[m]<=ty2)
							count++;
					}
					if(count>=k1 && area<minar){
						minar=area;
						//cout<<tx1<<" "<<tx2<<" "<<ty1<<" "<<ty2<<" "<<count;
					}
					//count=0;
				}
			}
		}
	}
	cout<<minar<<"\n";
}

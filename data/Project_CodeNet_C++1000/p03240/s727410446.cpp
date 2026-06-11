#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100],y[100];
ll h[100];

int main()
{
	int n;
	cin>>n;
	for( int i=0; i<n; i++ )
	{
		cin>>x[i]>>y[i]>>h[i];
	}
	for( int cx=0;cx<=100;cx++)
	{
		for( int cy=0;cy<=100;cy++)
		{
			ll H;
			for( int i=0; i<n; i++)
			{
				if( h[i] != 0 )
				{
					H = abs(cx-x[i])+abs(cy-y[i])+h[i];
					break;
				}
			}
			bool ok = true;
			for( int i=0; i<n; i++)
			{
				if( ( h[i]!=0 && abs(cx-x[i])+abs(cy-y[i])+h[i] != H )
				    ||( h[i]==0 && abs(cx-x[i])+abs(cy-y[i])+h[i] < H ) )
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				cout << cx <<" "<< cy<<" " << H << endl;
				return 0;
			}
		}
	} 
	
		
	return 0;
}

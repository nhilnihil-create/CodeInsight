#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define FLASH ios::sync_with_stdio(0);cin.tie(0);
#define all(v)  v.begin(),v.end()
const int inf=1e9+7;
const int mod=1e9+7;
const ll INF=1e18;	

bool sz(int a,int b)
{
	return a>b;
}

						void solve()
						{
							
							ll x,y;
							cin>>x>>y;
							
							if(x%y==0)
							{
								cout<<-1;
							}
							else
							{
								cout<<x;
							}
							
								
						
						}




int main()
{	
	FLASH
	int t=1;
	
	while(t--)
	{
		solve();
	}
	
}
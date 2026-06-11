#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll p=3;

ll happy(ll n,ll h[][3])
{
    ll t[n][3];
    
    for(int j=0;j<3;j++)
    {
        t[0][j]=h[0][j];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            t[i][j]=h[i][j]+ max(t[i-1][(j+1)%p], t[i-1][(j+2)%p] );
        }
    }
    
    ll largest=max( t[n-1][0], max( t[n-1][1], t[n-1][2] ) );
    
    return largest;
}

int main() {
	
	ll n;
	cin >>n;
	ll h[n][3];
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<3;j++)
	    cin >>h[i][j];
	}
	
	std::cout << happy(n,h) << std::endl;
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl

int main() {
	// your code goes here
	ll t;
	t=1;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    char M[n][m];
	    for(ll i=0;i<n;i++)
	    {
	        for(ll j=0;j<m;j++)
	        {
	            cin>>M[i][j];
	        }
	    }
	    ll frow=0;
	    ll fcol=0;
	    ll T[n][m];
	    for(ll i=0;i<n;i++)
	    {
	        if(M[i][0]=='#')
	        {
	        T[i][0]=0;
	        fcol=1;
	        }
	        else if(fcol ==1)
	        T[i][0]=0;
	        else
	        T[i][0]=1;
	    }
	    for(ll j=0;j<m;j++)
	    {
	        if(M[0][j]=='#')
	        {
	        T[0][j]=0;
	        frow=1;
	        }
	        else if(frow==1)
	        T[0][j]=0;
	        else
	        T[0][j]=1;
	    }
	    for(ll i=1;i<n;i++)
	    {
	        for(ll j=1;j<m;j++)
	        {
	            if(M[i][j]=='#')
	            T[i][j]=0;
	            else
	            T[i][j]=(T[i-1][j]+T[i][j-1])%MOD;
	        }
	    }
	    /*for(ll i=0;i<n;i++)
	    {
	        for(ll j=0;j<m;j++)
	        {
	            cout<<T[i][j]<<" ";
	        }
	        cout<<"\n";
	    }
	    */
	    cout<<T[n-1][m-1];
	}
	return 0;
}

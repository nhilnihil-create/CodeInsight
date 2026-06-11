#include <bits/stdc++.h>
using namespace std;


#define ONSPEED ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define f(i,x,n) for(i=x;i<n;i++)
#define rf(i,x,n) for(i=n;i>x;i--)
#define ll long long
#define GCD(a,b) __gcd(a,b)
#define ff first
#define ss second
#define adios return 0;

/*
tacet aquilae
*/

int main()
{
    ONSPEED;
    ll t,n,k,a,b,c,d,s=0,i,j,flag;
    string x,y;
    cin>>n;
    std::vector<ll> V(n), C(n);
    f(i,0,n) cin>>V[i];
	f(i,0,n) cin>>C[i];
	f(i,0,n)
	{
		if(V[i]>C[i])
		{
			s+=V[i]-C[i];
		}
	}
	cout<<s<<endl;




    adios;
}
	

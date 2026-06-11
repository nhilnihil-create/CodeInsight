//lamia 2k19
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define ll          long long int
#define T           long long int t;scanf("%lld",&t);while(t--)
#define CS          cout<<"Case "<<cs++<<": "
#define nd          endl
#define dd          double
#define ss          string
#define Y           cout<<"YES"<<endl
#define N           cout<<"NO"<<endl
#define for0(i,n)   for( i=0;i<n;i++)
#define forn(n,i)   for( i=n-1;i>=0;i--)
deque<ll>dq;
vector<ll>v;
map<ll,ll>m;

int main()
{
	long long int n,a;
	cin>>n;
	cin>>a;
	ll gcd=a;
	n--;
    while(n--)
    {
        cin>>a;
        gcd=__gcd(gcd,a);
        
    }
    cout<<gcd<<nd;
	return 0;
}


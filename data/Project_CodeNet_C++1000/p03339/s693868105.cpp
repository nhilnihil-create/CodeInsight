

/* Great things never come from comfort zones,
"whatever the mind of a man can conceive and believe,it can achieve." */
 
#include <bits/stdc++.h>
#define ll long long
#define scf(n) scanf("%d",&n)
#define lscf(n) scanf("%lld",&n)
#define lpri(n) printf("%lld ",n)
#define pri(n) printf("%d ",(int)n)
#define prin(n) printf("%d\n",(int)n)
#define lprin(n) printf("%lld\n",n)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define inf INT_MAX
#define ninf INT_MIN
#define gcd __gcd
#define bitcount(n) __builtin_popcount(n)
using namespace std;
const ll mod =1e9+7;
const int N = 1e6+7;

int main()
{
       
			int n,a=0,b=0,ans=0;
			scf(n);

			string x,s;
			cin>>x;
			
			rep(i,0,n)
			(x[i]=='E')?s.pb('A'):s.pb('B');
			
			
			rep(i,0,n)
			{	
				if(s[i]=='A')
				a++;
			}

			ans=a;

			rep(i,0,n)
			{
				if(s[i]=='A')
				a--;

				else 
				b++;

				ans=min(ans,a+b);
			}

			prin(ans);

		}


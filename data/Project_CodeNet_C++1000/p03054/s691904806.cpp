		#include <bits/stdc++.h>
		using namespace std;
		typedef long long ll;
		#define PI 3.14159265358979
		#define EPS 1e-8
		#define mod  998244353
		#define fi first
		#define se second
		#define mp make_pair
		#define pb push_back
		#define endl "\n"
			 
		const ll INF=1e15;	
		const int N=2e5+50;
		 

		 
		long long binpow(long long a, long long b, long long m) {
			a %= m;
			long long res = 1;
			while (b > 0) {
				if (b & 1)
					res = res * a % m;
				a = a * a % m;
				b >>= 1;
			}
			return res;
		}
		
		ll modinverse(ll a,ll m)
		{
			return binpow(a,m-2,m);
		}
		
			
		
		
		int main()
		{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);cout.tie(0);
		
					
			ll h,w,n;
			cin>>h>>w>>n;
			
			ll r,c;
			cin>>r>>c;
			
			
			string s,t;
			
			ll l1=c,r1=c,u1=r,d1=r;
			ll l2=0,r2=0,u2=0,d2=0;
			
			ll f=1;
			
			cin>>s;
			cin>>t;
			for(ll i=0;i<s.length();i++)
			{
				if(s[i]=='D')
				{
					if(!u2)
						d1++;
					else
						u2--;
				}
				else if(s[i]=='R')
				{
					if(!l2)
						r1++;
					else
						l2--;
				}
				else if(s[i]=='L')
				{
					if(!r2)
						l1--;
					else
						r2--;
					
				}
				else
				{
					if(!d2)
						u1--;
					else
						d2--;
				}
				
				if(l1<=0 || u1<=0)
					f=0;
			
				if(d1>h || r1>w)
					f=0;
					
				if(t[i]=='D')
				{
					if(u1==r)
						d2++;
					else
						u1++;
					
					d2=min(d2,h-r);
				}
				else if(t[i]=='R')
				{
					if(l1==c)
						r2++;
					else
						l1++;
						
					r2=min(r2,w-c);
				}
				else if(t[i]=='L')
				{
					if(r1==c)
						l2++;
					else
						r1--;
						
					l2=min(l2,c-1);
				}
				else
				{
					if(d1==r)
						u2++;
					else
						d1--;
					
					u2=min(u2,r-1);
				}
			
			
			
			}
			
			if(f)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
			
			
		

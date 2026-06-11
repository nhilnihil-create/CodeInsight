#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define imx INT_MAX
#define imn INT_MIN
#define llmx LLONG_MAX
#define llmn LLONG_MIN

#define fi first
#define se second
#define pb push_back
#define f_s(a) sort(a.begin(), a.end())
#define b_s(a) sort(a.rbegin(), a.rend())
#define p(a) cout<<a<<"\n"


// ll mod = 1000000007;
// #define l(i, )
// #define rl(i, a, b) for(int i = a; i < b; i++)

/////////////////////GCD//////////////////////
ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}


ll extended_gcd(ll a, ll b, ll& x, ll& y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll x1, y1;
	ll d = extended_gcd(b, a%b, x1, y1);
	x=y1;
	y=x1-y1*(a/b);
	return d;
}

////////////////////SIEVE OF ERATOSTHENES//////////////////////
vector<int> sieveoferatosthenes(int n)
{
	vector<bool> prime(n+1, true);
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(prime[i])
		{
			for(int j = i*i; j<=n; j+=i)
			{
				prime[j]=false;
			}
		}
	}
	vector<int> all_primes;
	for(int i = 2; i <=n; i++)
	{
		if(prime[i]) all_primes.pb(i);
	}
	return all_primes;
}

////////////////////BINARY EXPONENTIATION///////////////////////
ll bin_exp(ll a, ll b, ll mod)
{
	ll ans = 1;
	while(b)
	{
		if(b%2)
		{
			b--;
			ans = (ans%mod*a%mod)%mod;
		}
		b/=2;
		a = (a%mod*a%mod)%mod;
	}
	return ans;
}


bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
	if(a.fi!=b.fi) return a.fi>b.fi;
	return a.se>b.se;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue <ll, vector<ll>, greater<ll> > pq; 
	ll n, m, x, y;
	cin>>n>>m;
	vector<ll> a(n);

	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a.begin(), a.end());

	vector<pair<ll, ll> > z(m);

	ll ct = 0;
	for(int i = 0; i < m; i++)
	{
		cin>>z[i].se>>z[i].fi;
		ct+=z[i].se;
	}
	sort(z.begin(), z.end(), cmp);


	ll k = 0, l = 0;
	ll sum = 0;
	for(ll i = 0; i < min(n, ct); i++)
	{
		if(l==z[k].se) 
		{
			k++;
			l=0;
		}
		sum+=max(a[i], z[k].fi);
		a[i]=max(a[i], z[k].fi);
		l++;

	}

	for(ll i = min(n, ct); i < n; i++) sum+=a[i];

	// for(auto i: a) cout<<i<<" ";
	// cout<<endl;

	// for(auto i:z)
	// {
	// 	cout<<i.fi<<" "<<i.se<<endl;
	// }

	// ll sum = 0;
	// for(int i = 0; i < n; i++)
	// {
	// 	cin>>a[i];
	// 	sum+=a[i];
	// 	// pq.push(x);
	// }
	// // cin>>m;
	// sort(a.begin(), a.end());
	// vector<pair<ll, ll> > z(m);
	// for(int i = 0; i < m; i++)
	// {
	// 	cin>>z[i].se>>z[i].fi;
	// 	// sum+=z[i]
	// }
	// sort(z.rbegin(), z.rend());
	// int k = 0, i = 0;
	// // ll ans=0;
	// // for(auto i:z)
	// // {
	// // 	cout<<i.first<<"  "<<i.se<<endl;
	// // }
	// // for(int i = 0; i < n; i++)
	// // {
	// // // for(int i = 0;)
	// // 	// cout<<z[k].se<<endl;
	// // 	for(int j = 0; j < z[k].se; j++)
	// // 	{
	// // 		// cout<<"i "<<i<<endl;
	// // 		// if(a[i]>z[k].fi)
	// // 		// {
	// // 		// 	k++;
	// // 		// 	break;
	// // 		// }
	// // 		if(z[k].fi>a[i])
	// // 			sum+=z[k].fi-a[i];
	// // 		// sum+=max(a[i], z[k].fi);
	// // 		// cout<<"a[i] "<<a[i]<<" z[k].fi "<<z[k].fi<<endl;
	// // 		// cout<<ans<<endl;
	// // 		i++;
	// // 	}
	// // 	i--;
	// // 	// i=z[k].se;
	// // 	k++;
	// // 	if(k>=m)
	// // 	{
	// // 		break;
	// // 	}
	// // }
	// // cout<<sum<<endl;
	// while(k<m and i<n)
	// {
	// 	for(int j = 0; j < z[k].se; j++)
	// 	{
	// 		// cout<<"z "<<z[k].fi<<endl;
	// 		// cout<<"a "<<a[i]<<endl;
	// 		if(z[k].fi>a[i])
	// 		{
	// 			sum+=z[k].fi-a[i];
	// 		}
	// 		// if(i>=n)
	// 		// {
	// 		// 	break;
	// 		// }
	// 		i++;
	// 	}
	// 	// cout<<"i "<<i<<endl;	
	// 	// i--;
	// 	k++;
	// }
	// for(int j = i; j < n; j++)
	// while(m--)
	// {
	// 	cin>>x>>y;
	// 	while(x>0 and pq.top()<y)
	// 	{
	// 		pq.pop();
	// 		pq.push(y);
	// 		x--;
	// 	}
	// }
	// ll sum=0;
	// while (pq.empty() == false) 
 //    { 
 //    	sum+=pq.top();
 //        // cout << pq.top() << " "; 
 //        pq.pop(); 
 //    } 

	// for(auto i:pq)
	// {
	// 	sum+=i;
	// }
	cout<<sum<<endl;
}
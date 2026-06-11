#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/detail/standard_policies.hpp>

// common
#define endl     "\n"
#define M_PI     3.14159265358979323846

// fast input output
#define fast_io  ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL)

// fixed float field
#define fix_prec cout.setf( std::ios::fixed, std:: ios::floatfield ); cout.precision(9);

// vector
#define vi       vector<int>
#define vvi      vector<vector<int>>
#define vpii     vector<pair<int,int>>
#define pb(v,x)  v.push_back(x)

// pair
#define pii      pair<int,int>
#define mp(a,b)  make_pair(a,b)
#define F        first
#define S        second

// sort
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()

// bound
#define lb(v,x)  lower_bound(v.begin(),v.end(),x)
#define ub(v,x)  upper_bound(v.begin(),v.end(),x)

using namespace std;
//using namespace __gnu_pbds;

//typedef tree < int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
typedef long long int lli;
typedef unsigned long long int ulli;

// constants
lli const mod  = 1e9+7;
lli const modl = 1e18;

// helper functions
// calculate gcd
lli gcd(lli x, lli y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

// calculate fibonacci number
lli fib(int n)
{
    lli a,b,c,i;
    a=0,b=1;
    if(n == 0)
        return a;
    for(i=2;i<=n;i++)
    {
    	c=a+b;
    	a=b;
    	b=c;
    }
    return b;
}

// check if number if prime
bool isprime(lli n)
{
	if(n<=1)
		return false;
	else if(n==2)
		return true;
	else if(n%2==0)
		return false;
	else
	{
		int i;
		for(i=3;i*i<=n;i++)
		{
			if(n%i==0)
				return false;
		}
		return true;
	}
}

// read from and write to text file
void readwrite()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
} 

// seive
vector<lli>prime(100000+7,1);
void buildprime(lli n)
{
	lli i,j;
	prime[0]=prime[1]=0;
	for(i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=n;j+=i)
				prime[j]=0;
		}
	}
}

// nCr
lli dp[1005][1005];
lli comb[1005][1005];
lli ncr(lli n,lli r)
{
	if(n==r)
		return 1;
	if(r==0)
		return 1;
	if(r==1)
		return n;
	if(dp[n][r]!=0)
		return dp[n][r];
	return dp[n][r] = (ncr(n-1,r)%mod+ncr(n-1,r-1)%mod)%mod;
}

void ncrm()
{
	comb[0][0]=1;
	for(int i=1;i<1001;i++)
	{
		comb[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			comb[i][j]=(comb[i-1][j]%mod+comb[i-1][j-1]%mod)%mod;
		}
	}
}

// binary exponentiation
lli binpowm(lli a,lli b)
{
	lli res=1;
	a%=mod;
	while(b)
	{
		if(b&1)
			res=((res%mod)*(a%mod))%mod;
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return res%mod;
}
 
// factorial
lli fact(lli n)
{
	lli i,res=1;
	for(i=1;i<=n;i++)
		res=((res%mod)*(i%mod))%mod;
	return res%mod;
}

// driver code
void solve()
{
	lli n,m,i,ans=0;
	string s;
	cin>>s;
	n=s.length();
	m=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='B')
			m++;
		else
			ans+=m;
	}
	cout<<ans;
}

int main()
{
  fast_io;
  fix_prec;
  //readwrite();
  int t=1;
  //cin>>t;
  while(t--)
  {
    solve();
    cout<<endl;     
  }
  return 0;	
}

/*
Kab Khoon khaulega tera jab sabka internship lag jayega tab
Shame on you if you do not get internship
*/
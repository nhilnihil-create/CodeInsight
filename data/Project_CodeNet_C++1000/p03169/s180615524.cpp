#include <bits/stdc++.h>
using namespace std;
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%ld\n",a)
#define pll(a) printf("%lld\n",a) 
#define sc(a) scanf("%c",&a)a
#define pc(a) printf("%c",a)
#define ll long long
#define ld long double
#define mod 1000000007

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF INT_MAX
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define VI vector<int>
#define VL vector<ll>
#define PI pair<int,int>
#define PL pair<ll,ll>
long double PIE=acos(-1);
//////////////////////////////////////////////////////////////
const ll N=1e5+5;
ll Ans=1;
bool done[1000009];
vector < ll > primes;

void FindPrime(ll N)
{
    done[1] = 1;
    for(int i=2;i<=N;i++)
	{
        if(done[i]) continue;
        for(int j=i*2;j<=N;j+=i)
		{
            done[j] = 1;
        }
        primes.push_back(i);
    }
}

ll solve(ll Num)
{
    for(int i=0;i<primes.size();i++)
	{
    	int p=primes[i];
        if(p*p*p > Num) break;
        ll Count = 1;
        while(Num%p == 0)
		{
            Num /= p,Count++;
        }
        Ans *= Count;
    }
    ll sq = (ll)sqrt(Num);
    if(!done[Num]) 
	Ans *= 2;
    else if(sq*sq == Num && !done[sq]) 
	Ans *= 3;
    else if(Num != 1) 
	Ans *= 4;
    return Ans;
}


ll fact[N], invfact[N];



ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll modinv(ll k)
{
	return pow(k, mod-2, mod);
}


ll nCr(ll x, ll y)
{
	if(y>x)
		return 0;
	ll num=fact[x];
	num*=invfact[y];
	num%=mod;
	num*=invfact[x-y];
	num%=mod;
	return num;
}

void initinv()
{
	fact[0]=1;
	fr(i,1,N)
	{
		fact[i]=(i*fact[i-1])%mod;
	}
	invfact[N]=modinv(fact[N]);
	for(int i=N-1;i>=1;i--)
	{
		invfact[i]=((i+1)*invfact[i+1])%mod;
	}
}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
double p[310][310][310],e[310][310][310];
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	int cnt[4]={0};
	fr(i,1,n)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	p[cnt[1]][cnt[2]][cnt[3]]=1.0;
	for(int c=n;c>=0;c--)
	{
		for(int b=n;b>=0;b--)
		{
			for(int a=n;a>=0;a--)
			{
				if(a+b+c>n)
				continue;
				if(a==0&&b==0&&c==0)
				continue;
				
				double pw=(double) (n-a-b-c)/n;
				double ew=pw/(1-pw) +1;
				
				e[a][b][c]+=ew*p[a][b][c];
				//e[a][b][c]++;
				if(a!=0)
				{
					double pt=(double) a/(a+b+c); 
					p[a-1][b][c]+=p[a][b][c]*pt;
					e[a-1][b][c]+=e[a][b][c]*pt;
				}
				if(b!=0)
				{
					double pt=(double) b/(a+b+c);
					p[a+1][b-1][c]+=p[a][b][c]*pt;
					e[a+1][b-1][c]+=e[a][b][c]*pt;
				}
				if(c!=0)
				{
					double pt=(double) c/(a+b+c);
					p[a][b+1][c-1]+=p[a][b][c]*pt;
					e[a][b+1][c-1]+=e[a][b][c]*pt;
				}
			}
		}
	}
	cout<<fixed<<setprecision(10);
	cout<<e[0][0][0];
	return 0;
}




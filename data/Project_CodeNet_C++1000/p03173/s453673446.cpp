#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
#define inf 1e18
#define PI 3.14159265358979323846264338327950L
#define w(x) int x; cin>>x; while(x--)
using namespace std;
bool sieve[2000006];
void sieve_make() 
{
	memset(sieve,true,sizeof(sieve));
	sieve[0]=sieve[1]=false;
	for(int i=2;i*i<2000006;i++)
	{
		if(sieve[i])
		{
			for(int j=i*i;j<2000006;j+=i)
				sieve[j]=false;
		}
	}
}

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int modexp(int a,int b,int c)
{
	if(a==0) return 0;
	if(b==0) return 1;

	int ans;
	if(b%2==0)
	{
		int small=modexp(a,b/2,c);
		ans=(small*small)%c;
	}
	else
	{
		int small=modexp(a,b-1,c);
		ans=(a%c);
		ans=(small*ans)%c;
	}
	return (ans+c)%c;
}
bool sign(int x)
{
	if(x>0)
		return true;
	return false;
}
int kadane(int* a,int n)
{
	int loc=a[0],glo=a[0];
	for(int i=1;i<n;i++)
	{
		loc=max(a[i],loc+a[i]);
		glo=max(glo,loc);
	}
	return glo;
}
int prefix[101],dp[401][401];
int help(vector<int>& a,int i,int j)
{
	int s=0;
	for(int k=i;k<=j;k++)
		s+=a[k];
	return s;
}
int solve(vector<int>& a,int i,int j)
{
	if(i==j) return 0;

	int ans=inf;
	if(dp[i][j]!=-1) return dp[i][j];
	for(int k=i;k<j;k++)
	{
		int left=solve(a,i,k);
		int right=solve(a,k+1,j);
		ans=min(ans,left+right+(i==0?prefix[j]:prefix[j]-prefix[i-1]));
	}
	return dp[i][j]=ans;
}


int32_t main()
{
	ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
	
	
	
	
	memset(dp,-1,sizeof dp);
	int n;
	cin>>n;
	vector<int>a(n);
	int s=0;
	for(int i=0;i<n;i++){ cin>>a[i];
	}
	

	prefix[0]=a[0];

	for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+a[i];
	
	cout<<solve(a,0,a.size()-1);
	
}


#include <bits/stdc++.h>
#define int long long
#define thaonguyen main
#define endl '\n'
#define pb push_back

using namespace std;

const int ThaoNguyen = 3e5+5, mod = 998244353, inf = 1e15;

int gt[ThaoNguyen];

namespace THAONGUYEN
{
	string sum1(string a, string b)
	{
		string res="";
		int carry=0, x;
		while(a.length()<b.length())
		{
			a='0'+a;
		}
		while(b.length()<a.length())
		{
			b='0'+b;
		}
		for(int i=a.length()-1; i>=0; i--)
		{
			x=a[i]+b[i]-96;
			res=(char)(x%10+48+carry)+res;
			carry=x/10;
		}
		if(carry)
		{
			res='1'+res;
		}
		return res;
	}
	
	string mul1(string a, int b)
	{
		string res="";
		int carry=0, x;
		for(int i=a.length()-1; i>=0; i--)
		{
			x=(a[i]-48)*b+carry;
			res=(char)(x%10+48)+res;
			carry=x/10;
		}
		if(carry>0)
		{
			res=(char)(carry+48)+res;
		}
		return res;
	}
	
	string mul2(string a, string b)
	{
		string res="";
		for(int i=0; i<a.length(); i++)
		{
			res+='0';
			res=sum1(res, mul1(b, (int)(a[i]-48)));
			cout<<res<<endl;
		}
		return res;
	}
	
	void prep()
	{
		gt[1]=1;
		for(int i=2; i<ThaoNguyen-1; i++)
		{
			gt[i]=(gt[i-1]*i)%mod;
		}
	}
	
	int binpow(int n, int k, int mod)
	{
		int m = n%mod, i=1, ans=1;
		{
			while(i<=k)
			{
				int temp=i&k;
				if(temp>0)
				{
					ans=(ans*m)%mod;
				}
				i<<=1, m=(m*m)%mod;
			}
		}
		return ans;
	}
	
	int rev_mod(int n, int mod)
	{
		return binpow(n, mod-2, mod);
	}
	
	int C(int k, int n)
	{
		if(k==0||k==n)
		{
			return 1;
		}
		else
		{
			return ((((gt[n]%mod)*rev_mod(gt[k], mod))%mod)*rev_mod(gt[n-k], mod))%mod;
		}
	}
}

using namespace THAONGUYEN;

int n, a, b, k;
signed thaonguyen()
{
	ios::sync_with_stdio(false), cin.tie(0);
	prep();
	cin>>n>>a>>b>>k;
	int ans=0;
	for(int i=0; i<=n; i++)
	{
		if((k-i*a)%b==0)
		{
			int cac=(k-i*a)/b;
			if(cac>n||cac<0)
			{
				continue;
			}
			ans+=(C(cac, n)*C(i, n))%998244353;
			ans%=998244353;
//			int mat=cac+i-n;
//			cac-=mat;
//			int j=i-mat;
//			ans+=(((C(cac, n)*C(j, n-cac))%998244353)*C(mat, n-cac-j))%998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}
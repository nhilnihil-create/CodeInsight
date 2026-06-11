//Here I come unstoppable_N
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define booster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PB push_back
#define F first
#define S second
#define forn(i,n) for(int i=0;i<n;i++)

const int mod=1e9+7;
ll xor1_n(ll n){switch(n%4){case 0:return n;case 1:return 1;case 2:return n+1;}return 0;}
int ncr(int n,int r){ int res=1; if(r>n-r)r=n-r; for(int i=0;i<r;i++) {  res*=n-i;  res/=i+1; } return res; }
clock_t time_p=clock();
void rtime(){ time_p=clock()-time_p; cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}

string all[120];
int ind=0;
void permute(string s,int l,int r)
{
	int i;
	if(l==r)
	{
		all[ind++]=s;
		//cout<<s<<"\n";
	}
	else
	{
		for(i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			permute(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	booster;
	int t=1;
	//cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==b && b==c)
			cout<<"Yes";
		else cout<<"No";

	}
	rtime();
	return 0;
}
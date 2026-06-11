#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long int
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pss printf
#define MOD 1000000007
#define INF 1e18
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl

int l,ol;
int n,m=1;
int x[66],y[66],w[66];

int main()
{
	SPEED;
	cin>>l;
	ol=l;
	int in=0;
	int d[33]={0};
	while(l>0)
	{
		d[in++]=(l&1);
		l>>=1;
	}
	n=in;
	for(int i=1;i<n;i++)
	{
		x[m]=i;
		y[m]=i+1;
		w[m]=0;
		m++;
		x[m]=i;
		y[m]=i+1;
		w[m]=(1<<(n-i-1));
		m++;
	}
	for(int i=0;i<in-1;i++)
	{
		if(d[i])
		{
			ol^=(1<<i);
			x[m]=1;
			y[m]=n-i;
			w[m]=ol;
			m++;
		}
	}
	cout<<n<<" "<<m-1<<endl;
	for(int i=1;i<m;i++)
		cout<<x[i]<<" "<<y[i]<<" "<<w[i]<<endl;
	return 0;
}

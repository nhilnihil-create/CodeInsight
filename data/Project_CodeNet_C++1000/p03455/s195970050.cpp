#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);

int main()
{
	ll a,b;
	cin >> a >> b;
	ll c=a*b;
	if(c%2LL==0LL)
	{
		cout << "Even\n";
	}
	else
	{
		cout << "Odd\n";
	}
	return 0;
}

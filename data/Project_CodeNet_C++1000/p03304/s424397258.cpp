#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long                           //del this if TLE or MLE
#define ll long long
#define ld long double
#define pr pair<int,int>
#define prr pair<pr,int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fow(i,a,b,c) for(int i=a;i<=b;i+=c)
#define bck(i,a,b,c) for(int i=a;i>=b;i-=c)
#define fi first
#define se second
#define loop int tests;cin>>tests;while(tests--)

signed main()
{
	fastio;
//	freopen("SMTH.inp","r",stdin);
//	freopen("SMTH.out","w",stdout);
	double n,m,d,ans;
	cin>>n>>m>>d;
	if(d==0)
		ans=(m-1)/n;
	else
		ans=2*(n-d)*(m-1)/(n*n);
	cout<<fixed<<setprecision(7)<<ans<<"\n";
}


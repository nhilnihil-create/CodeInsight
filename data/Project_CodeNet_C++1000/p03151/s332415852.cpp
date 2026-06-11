#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<math.h>
#include<vector>
#include<set>
#include<queue>
#include<map>
#define forn(i,n) for(int (i)=0;i<(n);i++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MAXN=100005;
const int INF=2147483647;
const ll LINF=9223372036854775807;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
ll n,a[MAXN],b[MAXN],cnt,ans;
vector<ll>vec;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	forn(i,n)cin>>a[i];
	forn(i,n)cin>>b[i];
	forn(i,n)
	{
		if(a[i]<b[i])
		{
			cnt+=b[i]-a[i];
			ans++;
		}
		else if(a[i]>b[i])
			vec.pb(a[i]-b[i]);
	}
	sort(vec.begin(),vec.end(),cmp);
	forn(i,vec.size())
	{
		if(cnt==0)
		{
			cout<<ans<<endl;
			return 0;
		}
		if(cnt>vec[i])
		{
			ans++;
			cnt-=vec[i];
		}
		else
		{
			cnt=0;
			ans++;
		}
	}
	if(cnt==0)cout<<ans;
	else cout<<-1;
	return 0;
}

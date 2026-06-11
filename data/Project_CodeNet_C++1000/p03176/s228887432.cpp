#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long                           //del this if TLE or MLE
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
//#define fow(a,b,c) for(int i=a;i<=b;i+=c)
//#define bck(a,b,c) for(int i=a;i>=b;i-=c)
#define h first
#define a second
#define loop int tests;cin>>tests;while(tests--)

const int N=2e5+5;

int f[N];

pr tree[N];

int bit[N];

void update(int x, int val)
{
	for(int i=x;i<N;i+=(i&-i))
	{
		bit[i]=max(bit[i],val);
	}
}
int get(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=(i&-i))
	{
		ans=max(ans,bit[i]);
	}
	return ans;
}
signed main()
{
	int n;
	cin>>n;
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++)
		cin>>tree[i].h;
	for(int i=1;i<=n;i++)
	{
		cin>>tree[i].a;
		f[i]=tree[i].a;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=max(f[i],get(tree[i].h-1)+tree[i].a);
		update(tree[i].h,f[i]);
	}
	int output=0;
	for(int i=1;i<=n;i++)
		output=max(output,f[i]);
	cout<<output<<"\n";
}

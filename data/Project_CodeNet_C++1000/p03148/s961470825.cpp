#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <vector>
//const int maxn = 1e5+5;
#define ll long long
#define inf  0x3f3f3f3f
#define FOR(i,a,b) for( int i = a;i <= b;++i)
#define bug cout<<"--------------"<<endl

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//const int maxn = 110000;
using namespace std;

int n,k;
int vis[1000010];
struct node 
{
	int val,nub;
}a[1000010];
bool cmp(node x,node y)
{
	return x.val > y.val;
}
int main()
{

	//freopen("C:\\ACM\\input.txt","r",stdin);
	cin>>n>>k;
	for(int i = 1;i <= n; ++i) cin>>a[i].nub>>a[i].val;

	sort(a+1 ,a+1+n,cmp);
	
	stack<int>sta;

	ll sum1 = 0;
	ll sum2 = 0;
	//for(int i = 1;i <= n; ++i) cout<<a[i].nub<<" "<<a[i].val<<endl;
	for(int i = 1;i <= k; ++i)
	{
		if(vis[a[i].nub] == 1) sta.push(i);
		else 
		{
			vis[a[i].nub] = 1;
			sum2++;
		}
		sum1 += a[i].val;
	}
	//cout<<sum1 + sum2 * sum2<<endl;
	ll maxn = sum1 + sum2 * sum2;
	for(int i = k+1;i <= n; ++i)
	{
		
		if(sta.size() == 0) break;
		if(vis[a[i].nub] == 1) continue;
		int x = sta.top();
		sta.pop();
		sum1 = sum1 - a[x].val + a[i].val;
		sum2++;
		vis[a[i].nub] = 1;
		maxn = max(maxn,sum1 + sum2 * sum2);
	}
	cout<<maxn<<endl;

}
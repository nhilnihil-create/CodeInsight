#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             (1<<17)
#define vv(type)		vector<vector<type>>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define db(x) 			cout<<x<<" "
#define db1(x) 			cout<<x<<'\n'
#define db2(x,y) 		cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) 		cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) 		for(int i=0;i<(n);++i)
#define repA(i,a,n) 	for(int i=a;i<=(n);++i)
#define repD(i,a,n) 	for(int i=a;i>=(n);--i)
#define so(a) 			sort(a.begin(),a.end())
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// to find all local maximaa and minima in O(n)
//	 for (int i=1;i<=n;i++)
//        {
//            if (i==1 || i==n || (p[i-1]<p[i])!=(p[i]<p[i+1]))
//           ans.push_back(p[i]);
//        }

int dp[(1 << 16)];
int sums[(1 << 16)];
int preparesums(vector<vi>&score, int mask)
{
	int ans = 0;
	rep(i, 17)
	repA(j, i + 1, 16)
	{
		if ((mask & (1 << i)) && (mask & (1 << j)))
			ans += score[i][j];
	}
	return ans;
}
int solve(vector<vi>&score, int mask)
{
	if (mask == 0) return 0;
	if (dp[mask] != inf)
		return dp[mask];
	int ans = 0;
	for (int submask = mask; submask != 0; submask = (submask - 1)&mask)
		ans = max(ans, sums[submask] + solve(score, mask ^ submask));
	return dp[mask] = ans;
}
void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<vi>score(n, vi(n));
	rep(i, n)
	rep(j, n)
	cin >> score[i][j];
	sums[0] = 0;
	repA(subset, 1, (1 << n) - 1)
	dp[subset] = inf;
	repA(subset, 1, (1 << n) - 1)
	sums[subset] = preparesums(score, subset);
	db1(solve(score, (1 << n) - 1));
}
int32_t main()
{
	solve();
	return 0;
}

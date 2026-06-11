#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int S[211111];
int dp[211111];
int best[(1<<26)+2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	for(int i=1;i<(1<<26);i++) best[i]=int(1e9);
	dp[0] = 0;
	S[0] = 0;
	for(int i=0;i<n;i++)
	{
		S[i+1]=(1<<(s[i]-'a'));
		S[i+1]^=S[i];
	}
	for(int i=1;i<=n;i++)
	{
		int r=S[i];
		dp[i]=int(1e9);
		dp[i]=min(dp[i],best[r]+1);
		for(int j=0;j<26;j++)
		{
			dp[i]=min(dp[i],best[(1<<j)^r]+1);
		}
		best[r]=min(best[r],dp[i]);
	}
	cout<<dp[n]<<'\n';
}

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
typedef vector<vector<lli> > vvi;
typedef vector<ii> vii;
 
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
 
const int mod = 1e9 +7;
lli n, arr[410][410], inp[410], presum[410];
 
inline lli min(lli a, lli b)
{
	if(a<b)	return a;
	else return b;
}
 
lli dp(int l, int r)
{
	if(arr[l][r]<1e18) return arr[l][r];
	else if(l==r) return arr[l][r]=0;
	else
	{
		for(int i=l; i<r; i++)
			arr[l][r] = min(dp(l,i)+dp(i+1,r)+presum[r]-presum[l-1], arr[l][r]);
		return arr[l][r];
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=0; i<410; i++)
		for(int j=0; j<410; j++)
			arr[i][j]=1e18;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> inp[i], presum[i]=presum[i-1]+inp[i];
	cout << dp(1, n);
}
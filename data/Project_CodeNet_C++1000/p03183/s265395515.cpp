#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define eb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define output(x) cout<<x<<endl;
#define fre(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define frd(i, a, b) for (int i = (int)(a); i >= b; --i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

const int maxn = 1100;
ll dp[maxn][20*maxn];
int w[maxn],s[maxn];
ll v[maxn];

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);	
	int n;
	cin>>n;
	pair<int,int>p[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>w[i]>>s[i]>>v[i];
		p[i]={w[i]+s[i],i};
	}
	sort(p,p+n);
	// reverse(p,p+n);
	for (int i = 0; i < n; ++i)
	{
		int id=p[i].second;
		dp[i][w[id]]=v[id];
		if(i==0) continue;
		fre(j,1,s[id]){
			if(j+w[id] >= 20*maxn) break;
			dp[i][j+w[id]]=v[id]+dp[i-1][j];
		}
		fre(j,0,20*maxn){
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	ll ans=0;
	fre(i,0,20*maxn){
		ans=max(ans,dp[n-1][i]);
	}
	output(ans);
	return 0;
}
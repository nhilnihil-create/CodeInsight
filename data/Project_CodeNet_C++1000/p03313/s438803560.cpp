#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int N = 18;

int n, m, k, u, v, x, y, t, a, b;
int ans[1<<N];
pii dp[1<<N];

pii f(pii i, pii j){
	if (j.first>i.first) swap(i, j);
	return {i.first, max(i.second, j.first)};
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<(1<<n); i++) cin>>dp[i].first;
	for (int j=0; j<n; j++) for (int i=(1<<n)-1; i; i--) if (i&(1<<j)) dp[i]=f(dp[i], dp[i^(1<<j)]);
	for (int i=1; i<(1<<n); i++) cout<<(ans[i]=max(dp[i].first+dp[i].second, ans[i-1]))<<'\n';
	
	return 0;
}

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const int INF = 1e9+7;


int dp[1<<26];
int main(){
	//ios_base::sync_with_stdio(false);
	int ans=INF;
	string s;

	cin >> s;

	Fill(dp, INF);
	dp[0] = 0;
	int bitsum = 0;
	for(auto c: s){
		int bit = (1 << (c - 'a'));
		bitsum ^= bit;
		rep(k,26) chmin(dp[bitsum], dp[bitsum^(1<<k)] + 1);
	}
	ans = max(1, dp[bitsum]);

	cout << ans << endl;

	return 0;
}

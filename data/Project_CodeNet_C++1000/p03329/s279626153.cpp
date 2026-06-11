#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int pow(int a, int i){
	if(i==0) return 1;
	return a*pow(a,i-1);
}

int main(void){
	int n; cin >> n;
	vi md(1,1);
	for(int i=1;;i++){
		int a = pow(6,i);
		if(a>100000) break;
		md.push_back(a);
	}
	for(int i=1;;i++){
		int a = pow(9,i);
		if(a>100000) break;
		md.push_back(a);
	}
	SORT(md);
	vi dp(n+1,INF);
	dp[0] = 0;
	rep(i,n){
		rep(j,md.size()){
			int b = md[j];
			if(i+1-b<0) break;
			dp[i+1] = min(dp[i+1],dp[i+1-b]+1);
		}
	}
	cout << dp[n] << endl;
}

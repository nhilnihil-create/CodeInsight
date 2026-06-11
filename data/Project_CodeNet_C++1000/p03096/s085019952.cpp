#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;
 
#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
 
using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


ll dp[200010];
 
int main(){
	int N; cin >> N;
	vector<int> C(N);
	rep(i,N) cin >> C[i];
	C.erase(unique(C.begin(),C.end()),C.end());
	int M = C.size();
	dp[0] = 1;
	vector<int> before(200010,-1);
	rep(i,M){
		if(before[C[i]] == -1){
			dp[i+1] = dp[i];
			dp[i+1] %= MOD;
		}
		else{
			dp[i+1] = dp[i] + dp[before[C[i]]+1];
			dp[i+1] %= MOD;
		}
		before[C[i]] = i;
	}
	cout << dp[M] << endl;
}

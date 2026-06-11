// see https://gist.github.com/LumaKernel/ff55d49ee1af69b7388f15b707e75c15
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <complex>
#include <random>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<P> VP;

#define omajinai ios::sync_with_stdio(false);cin.tie(0)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RREP(i,n) RFOR(i,0,n)

#define LFOR(i,a,b) for(ll i=(a);i<(b);++i)
#define RLFOR(i,b,a) for(ll i=(b)-1;i>=(a);--i)

#define ALL(a) (a).begin(),(a).end()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define MP make_pair
#define PB push_back
#define EACH(i,c) REP(i,(int)(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define dump(x) cerr << "[L " << __LINE__ << "] " << #x << " = " << (x) << "\n";
#define dump2(x,y) cerr << "[L " << __LINE__ << "] " << #x << " = " << (x)\
			<< " , " << #y << " = " << (y) << "\n";

const int INF = 1e9;
const double EPS = 1e-10;
const int _N = 2e5;

int n,m;

int sub[1<<26];
int dp[_N];
int state[_N];
int cnt[26];

int main() {
	string s;
	cin >> s;
	n = s.size();
	REP(i,n){
		cnt[s[i]%26]++;
		REP(j,26)
			if(cnt[j]%2)
				state[i]|=1<<j;
	}
	REP(i, 1<<26){
		sub[i]=INF;
	}
	dp[0]=1;
	sub[state[0]] = dp[0];
	sub[0] = 0;

	FOR(i, 1, n){
		dp[i] = INF;
		dp[i] = min(dp[i], sub[state[i]]+1);
		REP(j,26){
			dp[i] = min(dp[i], sub[state[i]^(1<<j)]+1);
		}
		sub[state[i]] = min(sub[state[i]], dp[i]);
	}

	cout << dp[n-1] << endl;
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

bool F[30][MAX+1];

int main() {
	int n,c;cin>>n>>c;
	rep(i,c) rep1(j,n) F[i][j]=false;
	rep(i,n) {
		int s,t,c2;cin>>s>>t>>c2;c2--;
		for(int j=s;j<=t;j++) F[c2][j]=true;
	}
	int ans=0;
	rep1(i,MAX) {
		int t_ans=0;
		rep(j,c) {
			if(F[j][i]) t_ans++;
			ans=max(ans,t_ans);
		}
	}
	cout<<ans<<endl;
}

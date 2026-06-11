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
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
	int N,Z,W; cin >> N >> Z >> W;
	vector<int> a(N);
	rep(i,N) cin >> a[i];
	if(N == 1){
		cout << abs(a[0]-W) << endl;
		return 0;
	}
	int ans = max(abs(a[N-1]-W),abs(a[N-1]-a[N-2]));
	cout << ans << endl;
}


#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef tuple<ll,int,int> T;
const ll INF = 1000000000;
const ll MOD = 1000000007;

ll ans = 1e18;

vector<ll> l;
ll n,a,b,c;
void solve(ll num,ll A,ll B,ll C,ll L1,ll L2,ll L3){
	if(num == n && A >= 1 && B >= 1 && C >= 1){
		ll cost = (A + B + C - 3) * 10 + abs(L1-a) + abs(L2-b) + abs(L3-c);
		ans = min(ans,cost);
		return;
	}
	else if(num == n)return;
	solve(num+1,A+1,B,C,L1+l[num],L2,L3);
	solve(num+1,A,B+1,C,L1,L2+l[num],L3);
	solve(num+1,A,B,C+1,L1,L2,L3+l[num]);
	solve(num+1,A,B,C,L1,L2,L3);
}

int main(){
	cin >> n >> a >> b >> c;
	l.resize(n);
	for(ll i = 0;i < n;i++)cin >> l[i];
	solve(0,0,0,0,0,0,0);

	cout << ans << endl;
}

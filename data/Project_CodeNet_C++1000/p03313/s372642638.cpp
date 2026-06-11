#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[1<<18];
P p[1<<18];
llint cum[1<<18];

P merge(P &p, P &q)
{
	vector<llint> vec;
	vec.push_back(p.first);
	vec.push_back(p.second);
	vec.push_back(q.first);
	vec.push_back(q.second);
	sort(vec.rbegin(), vec.rend());
	return P(vec[0], vec[1]);
}

P zeta_transform(P a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if((j&(1<<i))) a[j] = merge(a[j], a[j^(1<<i)]);
		}
	}
}

int main(void)
{
	cin >> n;
	llint N = 1<<n;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) p[i] = P(a[i], -inf);
	
	zeta_transform(p, n);
	
	for(int i = 1; i < N; i++){
		cum[i] = max(cum[i-1], p[i].first + p[i].second);
		cout << cum[i] << endl;
	}
	
	return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,m;
	cin >> n >> m;
	vector<P> ab(n);
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b ;
		ab[i] = P(a,b);
	}

	ll ans = 0;
	sort(ab.begin(),ab.end());
	for(int i = 0;i < n;i++){
		ll plus = (ll)min(m,ab[i].second) * ab[i].first;
		m -= min(m,ab[i].second);
		ans += plus;
		if(m == 0)break;
	}

	cout << ans << endl;
}

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <stack>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
const int mxn = 1e6+10;
int a[mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];

	map<long long, int> f;
	long long ans = 0, cur = 0;
	for(int i=1; i<=n; i++) {
		cur+=1ll*a[i];
		if(cur==0) ans++;
		ans+=f[cur];
		f[cur]++;
	}

	cout << ans << '\n';


	return 0;
}
//comparator function in sorting
//swapping arguments
//missing cases in dp
//dividing in modulo
//Beware of overflow and modulo
//Be mindful of overflow
//s is a matrix but forget
//length of ranges
//working with bit using ull
#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	vector<int>p(n);
	rep(i, 0, n)cin >> p[i];
	sort(p.begin(), p.end());

	int fst = upper_bound(p.begin(), p.end(), a) - p.begin();
	int snd = upper_bound(p.begin(), p.end(), b) - upper_bound(p.begin(), p.end(), a);
	int trd = p.end() - upper_bound(p.begin(), p.end(), b);
	int ans;
	ans = min(fst, snd);
	ans = min(ans, trd);
	cout << ans << endl;
} 
 
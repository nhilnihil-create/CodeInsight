#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

int N;
LL A, B;

int p[10000], pos[10000];

LL dp[6000][6000];

LL cnt[6000][6000];

LL memo(int idx, int largest) {
	if (idx < 0 || largest < 0)
		return 0LL;
		
	LL &ret = dp[idx][largest];
	if (ret != -1)
		return ret;
		
	if (p[idx] == largest)
		return ret = memo(idx - 1, largest - 1);
		
	if (p[idx] > largest)
		return ret = memo(idx - 1, largest);
		
	if (pos[largest] > idx)
		return ret = memo(idx, largest - 1);
		
	ret = A + memo(idx, largest - 1);
	LL tmp = B * (cnt[largest][idx + 1] - cnt[largest][pos[largest]]);
/*	ffor (i, pos[largest], idx + 1)
		if (p[i] < largest)
			tmp += B;*/
	ret = min(ret, tmp + memo(pos[largest] - 1, largest - 1));
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> A >> B;
	
	FOR (i, N) {
		cin >> p[i];
		p[i]--;
		pos[p[i]] = i;
	}
	
	FOR (i, N) {
		cnt[i][0] = 0;
		FOR (j, N)
			cnt[i][j + 1] = cnt[i][j] + (p[j] < i);
	}
	
	SET(dp, 255);
	cout << memo(N - 1, N - 1) << endl;
	
	return 0;
}
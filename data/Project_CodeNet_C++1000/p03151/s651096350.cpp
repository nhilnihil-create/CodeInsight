//by rng_59
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int (i)=0; i<(int)(n); i++)

const int MAXN = 100010;
long long a[MAXN],b[MAXN];

int main(void) {
	int N;
	long long ans = 0,poor = 0;
	cin >> N;
	REP(i,N) cin >> a[i];
	REP(i,N) cin >> b[i];
	priority_queue <int> q;
	REP(i,N)
		if(a[i] < b[i]) {
			poor += abs(a[i]-b[i]);
			ans++;
			
		}
		else q.push(abs(a[i]-b[i]));
	while(!q.empty() && poor > 0) {
		poor -= q.top();
		q.pop();
		ans++;
	}
	if(poor > 0) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}

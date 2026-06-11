#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
int main () {
	int N, K;
    cin >> N >> K;
	ll ans = 0;
	for (int b = 1; b <= N; ++b) {
		int p = N/b;
		int r = N%b;
		ans  += max(0,b-K) * p + max(0, r - K + 1);
	}
	if (K==0) {
		ans -= N;
	}
	cout << ans << endl;
    return 0;
}
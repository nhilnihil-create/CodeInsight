#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define co(x) cout << (x) << "\n"
#define ll long long
#define pb push_back
#define Never
#define To

using namespace std;

int main(){

	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, K;

	cin >> N >> K;
	
	ll ans = 0;
	for(ll b = 1; b <= N; b++){
		ans += (N / b) * max(0LL, (b - K));
		ans += max(0LL, N % b - K + 1);
	}

	if(K == 0) ans = N*N;

	cout << ans << endl;

	Never To return 0;
}

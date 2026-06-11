#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define MAP map<int,int>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;
const ll INF = (ll)1e17;


void ANS(bool flag) {
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Ans(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void ans(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}

int main() {
	int N; ull K;
	cin >> N >> K;
	vector<ull> A(N), B(N);
	REP(i, N) cin >> A[i] >> B[i];
	bool bit1[30] = {};
	REP(i, 30) if (K & (1 << i)) bit1[i] = true;

	ull sum = 0,value = 0;

	REP(j, N) if (K == (K | A[j])) sum += B[j];
	value = max(sum, value);

	REP(i, 30) {
		if (!bit1[i]) continue;
		ull K_ = K;
		bitset<30> bit(K_);
		bit.reset(i);
		REP(j, i) bit.set(j);
		K_ = bit.to_ullong();
		sum = 0;
		REP(j, N) if (K_ == (K_ | A[j])) sum += B[j];
		value = max(sum, value);
	}
	cout << value << endl;
	
	return 0;
}

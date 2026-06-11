#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

int32 find(int32 x){
	FOR(i, 1, x+1){
		if(i*(i+1)/2 == x) return i;
	}
	return -1;
}

int main(void){
	int32 N;
	cin >> N;
	int32 x = find(N);
	vector<vector<int32>> v;
	if(x == -1){
		cout << "No" << endl;
		return 0;
	}
	int32 now = 1;
	REP(i, x){
		v.push_back(vector<int32>());
		REP(j, i+1){
			v[i].push_back(now++);
		}
	}
	cout << "Yes" << endl << x+1 << endl;
	REP(i, x){
		int32 px = 0, py = i;
		cout << x << " ";
		while(px < i+1){
			cout << v[py][px++] << " ";
		}
		px--;
		py++;
		while(py < x){
			cout << v[py++][px] << " ";
		}
		cout << endl;
	}
	cout << x << " ";
	REP(i, x) cout << v[i][i] << " ";
	cout << endl;
}

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

/*
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int64 N, X;
	cin >> N >> X;
	vector<int64> x(N), sumby2(N+1, 0);
	REP(i, N){
		cin >> x[i];
		sumby2[i+1] += sumby2[i]+2*x[i];
	}
	reverse(all(x));
	int64 res = X+x[0]*2;
	priority_queue<int64, vector<int64>, greater<int64>> pq;
	pq.push(1);
	REP(i, N){
		int32 cnt = pq.top(); pq.pop();
		if(X+5*x[i] >= (cnt*2+1)*x[i]){
			res += (cnt*2+1)*x[i]+X;
			cnt++;
		}else{
			pq.push(2);
			res += 2*X+5*x[i];
		}
		pq.push(cnt);
	}
	cout << res << endl;
}
*/

int main(void){
	int64 N, X;
	cin >> N >> X;
	vector<int64> x(N+1, 0);
	REP(i, N) cin >> x[i];
	reverse(all(x));
	REP(i, N){
		x[i+1] += x[i];
	}

	int64 res = numeric_limits<int64>::max();
	FOR(i, 1, N+1){
		int64 sum = X*i+X*N;
		for(int64 j = 0;j*i < N;j++){
			if(j == 0){
				sum += (x[min((j+1)*i, N)]-x[j*i])*5;
			}else{
				sum += (x[min((j+1)*i, N)]-x[j*i])*(2*(j+1)+1);
			}
			if(sum > res) break;
		}
		res = min(res, sum);
	}
	cout << res << endl;
}

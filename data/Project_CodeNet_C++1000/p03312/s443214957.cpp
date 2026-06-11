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

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

int main(void) {
	int64 N;
	cin >> N;
	vector<int64> A(N), sum(N+1, 0);
	REP(i, N) cin >> A[i];
	REP(i, N) sum[i+1] += sum[i] + A[i];
	int64 res = INF_LL;
	REP(i, N) {
		auto bin = [&](int64 l, int64 r) {
			int64 ll = l, rr = r;
			int64 s = sum[r]-sum[l];
			int64 m;
			while (r-l > 1) {
				m = (l + r) >> 1;
				if (2*(sum[m]-sum[ll]) < s) {
					l = m;
				} else {
					r = m;
				}
			}
			return l;
		};
		int64 a = bin(0, i), b = bin(i, N);
		REP(pa, 2) REP(pb, 2) {
			vector<int64> v = {sum[a+pa], sum[i]-sum[a+pa], sum[b+pb]-sum[i], sum[N]-sum[b+pb]};
			sort(all(v));
			res = min(res, v[3]-v[0]);
		}
	}
	cout << res << endl;
}


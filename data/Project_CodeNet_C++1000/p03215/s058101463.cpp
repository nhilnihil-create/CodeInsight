#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int64_t i = 0; i < n; i++)
#define REPR(i, n) for(int64_t i = n; i >= 0; i--)
#define FOR(i, m, n) for(int64_t i = m; i < n; i++)
#define FORR(i, m, n) for(int64_t i = m; i >= n; i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
template<class T>
inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>
inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}
const ll INF= 1ll << 60;
const ll MOD = 1000000007;
double EPS = 1e-10;
//----------------------------------------------------------


long n, m;
long a[1005];
long sum[1005];//累積和
long psum[2000000];//部分和
long bitflag = 1;


int main(){
	scanf("%ld%ld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%ld", &a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	long pcnt = 0;
	for(int i = 0; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			psum[pcnt] = sum[j] - sum[i];
			pcnt++;
		}
	}
	long upmost = 0;
	for(long bitflag = 1; bitflag < 35184372088832; (bitflag <<= 1)){
		int cnt = 0;
		for(int i = 0; i < pcnt; i++){
			if(bitflag & psum[i]){
				cnt++;
			}
		}
		if(cnt >= m){
			upmost = bitflag;
		}
	}
	if(upmost == 0){
		printf("0\n");
		return 0;
	}
	std::set<int> st;
	for(int i = 0; i < pcnt; i++){
		st.insert(i);
	}
	while(upmost > 0){
		int cnt = 0;
		for(auto i = st.begin(); i != st.end(); i++){
			if(psum[*i] & upmost){
				cnt++;
			}
		}
		std::set<int> st2;
		if(cnt >= m){
			for(auto i = st.begin(); i != st.end(); i++){
				if(psum[*i] & upmost){
					st2.insert(*i);
				}
			}
			st = st2;
			st2.clear();
		}
		upmost >>= 1;
	}
	long ans = psum[*st.begin()];
	for(auto i = st.begin(); i != st.end(); i++){
		ans = (ans & psum[*i]);
	}
	printf("%ld\n", ans);
}
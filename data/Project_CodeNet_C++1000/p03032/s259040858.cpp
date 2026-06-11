#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define Fixed fixed << setprecision(12)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod1 = 1e9+7; 
constexpr int mod2 = 998244353;
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
  
inline int updiv(int a,int b){ return (a + b - 1) / b; }
 
constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int mink = min(n, k), res = -LINF;

	vector<int> a(n);

	rep(i,n){
		cin >> a[i];
	}

	for(int i = 0; i <= mink; ++i){
		for(int j = 0; j <= mink - i; ++j){
			vector<int> vec;
			for(int l = 0; l < i; ++l){
				vec.emplace_back(a[l]);
			}
			for(int l = 0; l < j; ++l){
				vec.emplace_back(a[n-l-1]);
			}
			sort(all(vec));
			int sum = 0, cnt = k - i - j;
			for(auto&& e : vec){
				if(cnt == 0 || e >= 0){
					sum += e;
				}else{
					--cnt;
				}
			}
			chmax(res, sum);
		}
	}

	cout << res << '\n';

	return 0;
}

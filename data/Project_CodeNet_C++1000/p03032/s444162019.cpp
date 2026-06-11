#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, k, a[55];
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	vector<int> v;
	v.push_back(INF);
	i64 A = 0;
	i64 ans = 0;
	for(int i = 0; i <= n; i++){
		if(i != 0){
			v.push_back(a[i-1]);
			A += a[i-1];
		}
		sort(v.begin(),v.end());
		vector<int> vv;
		vv.push_back(INF);
		i64 B = 0;
		for(int j = 0; i+j <= n; j++){
			if(j != 0){
				vv.push_back(a[n-j]);
				B += a[n-j];
			}
			sort(vv.begin(),vv.end());
			if(i+j > k) break;
			chmax(ans, A+B);
			int l = 0, r = 0;
			i64 C = 0;
			for(int ii = 0; ii+i+j < k; ii++){
				if(v[l] == INF && vv[r] == INF) break;
				if(v[l] < vv[r]){
					C += v[l];
					l++;
				}
				else{
					C += vv[r];
					r++;
				}
				chmax(ans, A+B-C);
			}
		}
	}
	cout << ans << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
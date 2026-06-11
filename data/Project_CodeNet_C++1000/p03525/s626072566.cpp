#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[101];
void solve(){
	cin >> n;
	bool ok = 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 0) ok = 0;
	}
	
	if(n > 23 || !ok){
		cout << 0 << endl;
		return;
	}
	
	int ma = 0;
	for(int i = 0; i < (1<<n); i++){
		bool b[24] = {};
		bool lp = 0;
		b[0] = 1;
		for(int j = 0; j < n; j++){
			if(i >> j & 1){
				if(b[24-a[j]]){
					lp = 1;
					break;
				}
				b[24-a[j]] = 1;
			}
			else{
				if(b[a[j]]){
					lp = 1;
					break;
				}
				b[a[j]] = 1;
			}
		}
		if(lp) continue;
		
		int mi = 1;
		bool fin = 0;
		for(int i = 1; i < 24; i++){
			mi = i;
			for(int j = 0; j < 24; j++){
				if(b[j] && b[(j+i)%24]){
					fin = 1;
					break;
				}
			}
			if(fin) break;
		}
		chmax(ma,mi);
	}
	cout << ma << endl;
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

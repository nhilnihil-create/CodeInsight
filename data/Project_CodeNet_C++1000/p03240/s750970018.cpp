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



int n, a[111],b[111],h[111];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> h[i];
	}
	
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			int H = 0;
			for(int k = 0; k < n; k++){
				if(h[k] == 0) continue;
				H = h[k]+abs(a[k]-i)+abs(b[k]-j);
				break;
			}
			bool ok = 0;
			for(int k = 0; k < n; k++){
				if(H == h[k]+abs(a[k]-i)+abs(b[k]-j)) continue;
				if(h[k] == 0 && H <= abs(a[k]-i)+abs(b[k]-j)) continue;
				ok = 1;
				break;
			}
			if(ok) continue;
			cout << i << " " << j << " " << H << endl;
			return;
		}
	}
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
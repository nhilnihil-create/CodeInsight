#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> ans(n);
	if(a == 1){
		if(n == b){
			rep(i,n) cout << n-i << " ";
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	else if(b == 1){
		if(n == a){
			rep(i,n) cout << i+1 << " ";
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	else if(n <= a || n <= b){
		cout << -1 << endl;
	}
	else{
		if(a <= b){
			rep(i,a) ans[i] = n - a + i + 1;
			int bound = n - a + 1;
			if(b < 2 || a < (n - a + b - 2) / (b - 1) || bound < b){
				cout << -1 << endl;
			}
			else{
				int idx = a;
				int cnt = 1;
				while(idx < n){
					rep(i,b-1){
						ans[idx++] = min(n - a - i, (b - 1) * cnt - i);
						if(idx == n) break;
					}
					++cnt;
				}
				rep(i,n) cout << ans[i] << " ";
				cout << endl;
			}
		}
		else{
			rep(i,b) ans[i] = b - i;
			int bound = n - b + 1;
			if(a < 2 || b < (n - b + a - 2) / (a - 1) || bound < a){
				cout << -1 << endl;
			}
			else{
				int idx = b;
				int cnt = 1;
				while(idx < n){
					rep(i,a-1){
						ans[idx++] = max(b + 1 + i, n - (a - 1) * cnt + i + 1);
						if(idx == n) break;
					}
					++cnt;
				}
				rep(i,n) cout << ans[i] << " ";
				cout << endl;
			}
		}
	}
	return 0;
}
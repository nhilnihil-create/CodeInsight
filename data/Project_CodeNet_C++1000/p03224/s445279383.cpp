#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define frep(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) frep(i, 0, (n))
#define rrep(i, n) for(int i = (n - 1); i >= 0; i--)
#define all(i, x) for(typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define pb push_back

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int MAX = 100010;
const int INF = 1e9;
const int MOD = 1000000007;
const string END = "\n";

void solve(){
	int n; cin >> n;
	if(n == 1){
		cout << "Yes" << END;
		cout << 2 << END;
		cout << 1 << " " << 1 << END;
		cout << 1 << " " << 1 << END;
		return;
	}
	int ans = 0;
	frep(i, 1, n+1){
		if(i * (i-1) == 2 * n){
			ans = i;
		}
	}
	if(ans >= 1){
		int r = (2 * n) / ans;
		int a[ans][r], s = r;
		int cnt = 0, now = 1;
		while(r > 0){
			rep(i, r){
				a[cnt][cnt + i] = now + i;
				a[i + cnt + 1][cnt] = now + i;
			}
			now += r;
			r -= 1;
			cnt += 1;
		}
		cout << "Yes" << END;
		cout << ans << END;
		rep(i, ans){
			cout << s << " ";
			rep(j, s){
				cout << a[i][j] << " ";
			}
			cout << END;
		}
	}else{
		cout << "No" << END;
	}
}

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	solve();
	return 0;
}

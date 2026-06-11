#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;

void Main(){
	
	ll H, W;
	cin >> H >> W;
	vvl v(H, vl(W));
	rep(i, H) rep(j, W) cin >> v[i][j];
	
	vvl A(H * W + 10, vl(2));
	ll flg = 1;
	ll cnt = 0;
	ll ans = 0;
	rep(i, H){
		rep(j, W){
			A[cnt][0] = i;
			if(flg) A[cnt][1] = j;
			else A[cnt][1] = W - 1 - j;
			cnt++;
		}
		flg ^= 1;
	}
	
	vvl vv = v;
	
	rep(i, H * W - 1){
		
		ll nx = A[i][0];
		ll ny = A[i][1];
		ll nnx = A[i + 1][0];
		ll nny = A[i + 1][1];
		
		if(vv[nx][ny] % 2){
			vv[nnx][nny] += 1;
			ans += 1;
		}
		
	}
	
	print(ans);
	
	rep(i, H * W - 1){
		
		ll nx = A[i][0];
		ll ny = A[i][1];
		ll nnx = A[i + 1][0];
		ll nny = A[i + 1][1];
		
		if(v[nx][ny] % 2){
			v[nnx][nny] += 1;
			cout << nx + 1 << " " << ny + 1  << " " << nnx + 1  << " " << nny + 1 ;
			print("");
		}
		
	}
		
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
    
	return 0;
	
}




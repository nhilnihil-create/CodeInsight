#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) do{}while(0)
#endif



vector<int> p;
ll n, a, b;


/*
	右へ移動するコストA
	左へ移動するコストB
	移動しなかった数だけを選ぶと単調増加数列になる
	
	p0～piで移動しなかった数の最大値がj以下のとき、コストの最小値がdp[i][j]
*/

int main(){
	cin >> n >> a >> b;
	p.resize(n+1);
	p[0] = 0;
	rep(i,n)
		cin >> p[i+1];
	n++;
	
	
	vector<ll> dp(n);
	for ( int i = 1; i < n; i++ ){
		int pi = p[i];
		ll dppi1 = dp[pi-1];
		
		rep(j,n){
			if ( j < pi ){
				dp[j] += a;
			}
			else if ( j == pi ){
				dp[j] = dppi1;
			}
			else {
				dp[j] = min( dp[j]+b, dppi1 );
			}
		}
		
		//rep(k,n)
		//	cout << dp[k] << " ";
		//cout << endl;
	}
	
	cout << dp[n-1] << endl;
	
	
	return 0;
}



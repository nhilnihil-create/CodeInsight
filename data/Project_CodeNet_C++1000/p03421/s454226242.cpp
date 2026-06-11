#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (s); i <= (t); ++i)
#define repD(i,t,s) for(int i = (t); i >= (s); --i)
#define rep(i,n) repU(i,0,n - 1)
#define rep1(i,n) repU(i,1,n)
#define all(v) begin(v),end(v)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n - 1) / (d) + 1)
#define parity(a,b) (((a)^(b)) & 1 ^ 1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = (1 << 30) - 1;
const ll INF_64 = (1LL << 62) - 1;
const int MOD = 1e9 + 7;

int N,A,B;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> A >> B;
	if(N == 1){
		if(max(A,B) > 1) cout << -1 << endl;
		else cout << 1 << endl;
		return 0;
	}
	if(A + B > N + 1 || N > (ll)A * B){
		cout << -1 << endl;
		return 0;
	}
	if(A == 1){
		rep(i,N) cout << N - i << ' ';
		cout << endl;
		return 0;
	}
	if(B == 1){
		rep1(i,N) cout << i << ' ';
		cout << endl;
		return 0;
	}
	int q = (N - B) / (A - 1);
	int r = (N - B) % (A - 1);
	rep(i,B) cout << B - i << ' ';
	int cur = B;
	rep(i,A - 1){
		int k = q;
		if(0 < r--) ++k;
		repD(j,k,1) cout << cur + j << ' ';
		cur += k;
	}
	cout << endl;
}




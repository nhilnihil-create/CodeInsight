#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int n, a, b, c;
vector<int> l;
int ret = 1e9;
int rec(int i, int A, int B, int C, int res){
	if(i == n){
		if(A != 0 && B != 0 && C != 0){
			return abs(a-A) + abs(b-B) + abs(c-C) + (res-3)*10;
		} else {
			return 1e9;
		}
	}

	// 4 通り
	chmin(ret, rec(i+1, A, B, C, res));
	chmin(ret, rec(i+1, A+l[i], B, C, res+1));
	chmin(ret, rec(i+1, A, B+l[i], C, res+1));
	chmin(ret, rec(i+1, A, B, C+l[i], res+1));

	return ret;
}
int main()
{
	cin >> n >> a >> b >> c;
	l.resize(n);
	rep(i,n) cin >> l[i];

	cout << rec(0,0,0,0,0) << endl;
}

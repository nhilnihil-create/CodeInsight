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

const int INF = 1e9+7;
vector<int> l;
int N, A, B, C;
int rec(int i, int a, int b, int c) {
	if(i == N){
		if(!a || !b || !c) return INF;

		return abs(a-A) + abs(b-B) + abs(c-C);
	}
	int res = rec(i+1, a, b, c);

	chmin(res, rec(i+1, a + l[i], b, c) + (a ? 10: 0));
	chmin(res, rec(i+1, a, b + l[i], c) + (b ? 10: 0));
	chmin(res, rec(i+1, a, b, c + l[i]) + (c ? 10: 0));

	return res;
}

int main()
{
	cin >> N >> A >> B >> C;
	l.resize(N);
	rep(i, N)cin>>l[i];
	cout << rec(0,0,0,0) << endl;

}

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

int N;

double dp[310][310][310];
double rec(int i, int j, int k){
	if(dp[i][j][k] >= 0) return dp[i][j][k];
	if(i + j + k == 0) return 0.0;

	double res = 0.0;
	if(i) res += rec(i-1, j, k) * i;
	if(j) res += rec(i+1, j-1, k) * j;
	if(k) res += rec(i, j+1, k-1) * k;

	res += N;
	res *= 1.0 / (i + j + k);

	return dp[i][j][k] = res;
}
int main()
{
	cin >> N;
	int one = 0, two = 0, three = 0;
	rep(i,N){
		int a;
		cin >> a;
		if(a == 1) ++ one;
		else if(a == 2) ++two;
		else ++three;
	}
	memset(dp, -1, sizeof(dp));
	cout << setprecision(10);
	cout << rec(one, two, three) << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
const int INF = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
int A[2][101];

int main() {
	cin >> N;
	for (int i = 0; i <2 ; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	int ans	 = 0;
	for (int j = 0; j < N; j++)
	{
		int tmp = 0;
		for (int k = 0; k <=j ; k++)
		{
			tmp += A[0][k];
		}
		for (int m = j; m < N; m++)
		{
			tmp += A[1][m];
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}

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
int N, M, Q;

vector<vector<int>> sum;
void buildSumTable(vector<int> L, vector<int> R){
	sum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for(int i = 0; i < M; i++){
		sum[L[i]][R[i]]++; // 其のマスにいくつ入っているか
	}

	for (int i = 1; i <= N; i++) { //1-indexed
		for(int j = 1; j <= N; j++){
			sum[i][j] += sum[i-1][j];
			sum[i][j] += sum[i][j-1];
			sum[i][j] -= sum[i-1][j-1];
		}
	}
}

int getSumRange(int L, int R) {
	int ans = sum[R][R] - sum[R][L-1] - sum[L-1][R] + sum [L-1][L-1];
	return ans;
}
int main()
{
	
	cin >> N >> M >> Q;
	vector<int> L(M), R(M);
	for(int i = 0; i < M; i++){
		cin >> L[i] >> R[i];
	}
	vector<int> p(Q), q(Q);
	for(int i = 0; i < Q; i++){
		cin >> p[i] >> q[i];
	}
	buildSumTable(L, R);

	for(int i = 0; i < Q; i++){
		int ans = getSumRange(p[i], q[i]);
		cout << ans << endl;
	}
}


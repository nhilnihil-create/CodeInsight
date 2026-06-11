#include <bits/stdc++.h>

#define REP(i, s,  n) for(int i = s;i < (n);i++)
#define VSORT(v) sort(v.begin(), v.end());
#define int64 long long
#define pb(a) push_back(a)
#define REP64(i, s,  n) for(int64 i = s;i < (n);i++)
#define INF 999999999
#define MOD 1000000007
using namespace std;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//---------------------------------------------------------------
//---------------------------------------------------------------

int64 N,P;

map<int64, int64> A;	// 特定の数　→　何乗か
						// 例：　A[2] = 3　→　２の３乗が含まれる
void calc(int64 x) {
	// ２　から　変数の２乗が元数以下の間、繰り返す
	int64 w = x;
	for(int64 i = 2; i * i <= x;  i++) {
		while(w % i == 0) {
			A[i]++;
			w /= i;
		}
	}
	// 最後に残った数も含める
	A[w]++;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> P;
	
	calc(P);
	
	int64 ans = 1;
	int64 w;
	for(auto a : A) {
		w = a.second / N;
		while(w > 0) {
			ans *= a.first;
			w--;
		}
	}
	cout << ans << endl;
	
	return 0;
}

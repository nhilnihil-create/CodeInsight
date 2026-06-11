#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N)cin>>A[i];
	// 前の数字と同じかソレ以下しか作れない。
	if(A[0] != 0) {
		cout << -1 << endl; return 0;
	}
	For(i,1,N){
		if(A[i-1] == A[i] || A[i-1] + 1 == A[i] || A[i-1] > A[i]){
		}// ok
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0;
	for(int i = N-1; i >= 0; i--){
		if(i == N-1) ans += A[i];
		else {
			if(A[i] == A[i+1]) ans += A[i];
			else {
				if(A[i] > A[i+1]) ans += A[i];
			}
		}
	}
	cout << ans << endl;
}

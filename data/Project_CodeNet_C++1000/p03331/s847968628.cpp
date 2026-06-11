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

int main()
{
	int n;
	cin >> n;
	int ans = 1e9;
	for(int a = 1; a <= n-1; a++){
		int A = a;
		int B = n - a;
		int tmp = 0;
		while(A!=0){
			tmp += A % 10;
			A /= 10;
		}
		while(B!=0){
			tmp += B % 10;
			B /= 10;
		}
		chmin(ans,tmp);
	}
	cout << ans << endl;
}

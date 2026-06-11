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
	vector<int> a(n);
	rep(i,n) cin >> a[i];

	int M = -1e9;
	int m = 1e9;
	int mi = -1, Mi = -1;
	rep(i,n){
		if(chmin(m,a[i])) mi = i;
		if(chmax(M,a[i])) Mi = i;
	}
	if(M - abs(m) >= 0){
		// 全部正にする
		vector<P> ans(0);
		rep(i,n){
			ans.push_back({Mi+1,i+1});
		}
		// 全部正になった
		// 後は累積和
		for(int i = 1; i <= n-1; i++){
			ans.push_back({i,i+1});
		}
		cout << ans.size() << endl;
		for(P x: ans){
			cout << x.first <<" " << x.second << endl;
		}
	} else {
		vector<P> ans(0);
		rep(i,n){
			ans.push_back({mi+1,i+1});
		}
		// 全部負になった。
		for(int i = n; i >= 2; i--){
			ans.push_back({i,i-1});
		}
		cout << ans.size() << endl;
		for(P x: ans){
			cout << x.first <<" " << x.second << endl;
		}
		
	}
}

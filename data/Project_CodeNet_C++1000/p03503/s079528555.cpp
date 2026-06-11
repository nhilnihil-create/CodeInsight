#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define leftunique(a) {sort((a).begin(),(a).end());(a).erase(unique((a).begin(),(a).end()),(a).end());}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
static const ll INF = 1LL << 60;
//Write From this Line

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> f(n,vector<int>(10));
	rep(i,n) rep(j,10) cin >> f[i][j];
	vector<vector<int>> p(n,vector<int>(11));
	rep(i,n) rep(j,11) cin >> p[i][j];

	ll ans = -1001001001;
	//rep(i,n){
	//	rep(j,10){
	//		cout << f[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//rep(i,n){
	//	rep(j,11){
	//		cout << p[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for(int tmp = 1; tmp < (1 << 10); tmp++) {
		bitset<10> bit = tmp;
		ll sum = 0; // お姉ちゃんがbitのように営業したときの利益
		rep(i,n) {
			int count = 0; // 同時営業数
			rep(j,10) {
				if(bit.test(j) && f[i][j] == 1){
					count++;
				}
			}
			sum += p[i][count];
		}
		chmax(ans,sum);
	}
	cout << ans << endl;
}

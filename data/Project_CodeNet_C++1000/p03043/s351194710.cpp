#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	int n, k;
	cin >> n >> k;
	cout << setprecision(15);
	double ans = 0;;
	// サイコロを振って i がでたときの勝率を全て足せば求まる。
	for(int i = 1; i <= n; i++){
		// i スタートのとき、何回2倍すればk以上になるか
		int tmp = i;
		int count = 0;
		while(tmp < k){
			tmp *= 2;
			count ++;
		}
		//debug(count);
		// count回連続で表が出ればok
		ans += 1./(1.* pow(2,count));
	}
	cout << ans/(1.*n) << endl;
}

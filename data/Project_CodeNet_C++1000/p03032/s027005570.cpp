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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	rep(i, n)cin>>v[i];
	
	ll ans = -1e9-9;
	for(int i = 0; i <= k; i++){
		for(int j = 0; i + j <= k; j++){
			ll now = 0 ;
			// 戻せる回数は, k - (i + j)
			int can_rev = k - (i + j);
			// 左i個、右からj個取り出す。
			vector<int> hand(0);

			rep(x,i){
				hand.push_back(v[x]);
				now += v[x];
				if(hand.size() >= n) break;
			}
			for(int x = 0; x < j; x++){
				if(hand.size() >= n) break;
				hand.push_back(v[n-1-x]);
				now += v[n-1-x];
			}
			sort(hand.begin(),hand.end());

			for(int x = 0; x < can_rev; x++){
				if(x >= hand.size())break;
				if(hand[x] <= 0) now -= hand[x];
			}
			chmax(ans,now);
		}
	}
	cout << ans << endl;
}

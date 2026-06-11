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
	int n, m;
	cin >> n >> m;

	vector<vector<int>> s(n);
	rep(i,m){
		int k;
		cin >> k;
		rep(j,k){
			int x;
			cin >> x;
			--x;
			// x を押すと i が反応
			s[x].push_back(i);
		}
	}
	vector<int> p(m);
	rep(i,m) cin >> p[i];

	int ans = 0;
	for(int tmp = 0; tmp < (1 << n); tmp++){
		bitset<10> bit(tmp);
		vector<int> kazu(m,0);

		rep(i,n){
			if(bit.test(i)){
				// スイッチ i を使う
				for(auto x:s[i]){
					kazu[x] = 1 - kazu[x];
				}
			}
		}

		bool f = true;
		rep(i,m){
			if(p[i] != kazu[i]) f=  false;
		}
		if(f) ans++;
	}
	cout << ans << endl;
}

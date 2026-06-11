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
	ll m, k;
	cin >> m >> k;
	if(k >= pow(2,m)){
		cout << -1 << endl;
		return 0;
	} else {
		if(m == 0){
			cout << "0 0" << endl;
		} 
		else if(m == 1){
			if(k==1) cout << - 1 << endl;
			else {
				cout << "0 0 1 1" << endl;
			}
		} else {
			vector<int> ans;
			rep(i,pow(2,m)){
				if(i!=k) ans.push_back(i);
			}
			ans.push_back(k);
			rep(i,pow(2,m)){
				cout << ans[i] << " ";
			}
			REV(ans);
			For(i,1,pow(2,m)){
				cout << ans[i] << " ";
			}
			cout << k << endl;
		}
	}
}

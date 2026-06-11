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
ll dp[105][2];
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)cin>>a[i];

	dp[0][0] = 1;
	rep(i,n){
		if(a[i] % 2) {
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = dp[i][1] * 3 + dp[i][0] * 2;
		}
		else{
			dp[i+1][0] = dp[i][0] * 2;
			dp[i+1][1] = dp[i][1] * 3 + dp[i][0];
		}
	}
	cout << dp[n][1] << endl;
}

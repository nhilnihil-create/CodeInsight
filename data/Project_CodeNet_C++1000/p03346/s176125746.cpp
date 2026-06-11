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
const int inf = 1e9;
vector<int> dp(100100, inf);
vector<int> dp2(100100, inf);

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n){
		cin>>a[i];
		a[i]--;
	}
	vector<int> b(n+1);
	rep(i,n){
		b[a[i]] = i;
	}
	ll res = 1, cnt = 1;
	rep(i,n) {
		if (b[i+1] > b[i]) {
			cnt++;	
		}
		else {
			res = max(res,cnt);
			cnt = 1;
		}
	}
	cout << n - res << endl;
}

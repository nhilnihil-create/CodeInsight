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
	ll n;
	cin >> n;
	string ans ="";
	while(n != 0){
		if(n % 2 == 0){
			ans += '0';
			n /= (-2);
		} else {
			ans += '1';
			if(n % 2 == -1) n += -1;
			n /= -2;
		}
	}
	reverse(ans.begin(),ans.end());
	if(ans.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << ans << endl;
}

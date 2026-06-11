#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >>a[i];
	int even = 0 ;
	int odd = 0 ;
	rep(i,n){
		if(a[i] % 2) odd ++ ;
		else even ++ ;
	}
	int minus = pow(2,even);
	ll ans = pow(3,n) - minus ;
	cout << ans << endl;
}

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
	int n;
	cin >> n;
	vector<int> fact(101,0);
	For(i,1,n+1){
		int now = 2;
		int mul = i;
		while(mul != 1 && now <= 10 ){
			if(mul % now == 0){
				mul /= now;
				fact[now]++;
			} else {
				now += 1;
			}
		}
		if(mul != 1) fact[mul] ++ ;
	}
	int ni = 0,  yon = 0, juyon = 0, nijuyon = 0, nanayon = 0;
	rep(i,101){
		if(fact[i] >= 2){
			ni ++;
		}
		if(fact[i] >= 4) yon ++;
		if(fact[i] >= 14) juyon++;
		if(fact[i] >= 24) nijuyon ++;
		if(fact[i] >= 74) nanayon ++;
	}
	ll ans = 0;
	ans += max(0, (yon * (yon - 1) * (ni-2)) / 2);
	ans += max(0,(juyon) * (yon - 1));
	ans += max(0,(nijuyon) * (ni - 1));
	ans += nanayon;
	cout << ans << endl;

}

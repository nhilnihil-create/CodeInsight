#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;
ll kake;
ll a,b;
bool f(ll num){
	if(num == 0)return true;
	ll tmp = (num - 1) / 2;
	//if(tmp+1 == a || tmp+1 == b)return ((num)+(num-1)*tmp-tmp*tmp <= kake);
	//cout << tmp << ' ' << (num)+(num-1)*tmp-tmp*tmp << ' ' << kake << endl;
	return ((num)+(num-1)*tmp-tmp*tmp < kake);
}

int main()
{
	int q;cin >> q;
	
	REP(u,q){
		cin >> a >> b;
		if(a > b)swap(a,b);
		kake = a*b;
		ll tp = 2000001000LL;
		ll ub = 0;
		
		while(abs(tp - ub) > 1){
			ll mid = (tp + ub) / 2;
			if(f(mid))ub = mid;
			else tp = mid;
			//cout << mid << endl;
		}
		if(a == b)cout << ub << endl;
		else cout << ub-1 << endl;
	}
	return 0;
}
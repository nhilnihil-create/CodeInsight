#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

ll beki(ll x){
	if(x==0) return 1;
	return 2*beki(x-1);
}

int main(){
	ll L;
	cin >> L;

	ll t = 0;
	ll pro = 1;
	while(pro <= L){
		pro *= 2;
		t++;
	}
	t--;
	pro /= 2;

	ll X = L - pro;
	ll m = 0;
	REP(i, t){
		if ((X>>i)&1) m++;
	}

	cout << t+1 << " " << 2*t+m << endl;
	REP(i, t){
		cout << i+1 << " " << i+2 << " " << 0 << endl;
		cout << i+1 << " " << i+2 << " " << beki(i) << endl;
	}


	ll tmp = pro;
	REP(i, t){
		if ((X>>i)&1){
			cout << i+1 << " " << t+1 << " " << tmp << endl;
			tmp += beki(i);
		}
	}

    return 0;
}
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

int main(){
	ll N;
	cin >> N;
	vector<ll> res;
	if(N==3){
		printf("2 5 63\n");
		return 0;
	}else{
		ll a = N/8;
		ll b = N%8;
		vector<ll> tmp = {2, 4, 3, 9, 8, 10, 6, 12};
		REP(i, a){
			ll ki = 12*i;
			REP(j, 8) res.push_back(ki+tmp[j]);
		}
		ll ki = 12*a;
		if(b%2==1){
			res.push_back(ki+6);
			b--;
		}
		REP(j, b) res.push_back(ki+tmp[j]);
	}
	REP(i, res.size()) cout << res[i] << " ";
	cout << endl;
    return 0;
}
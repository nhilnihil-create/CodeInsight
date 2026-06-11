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
	vector<ll> t(N), v(N);
	REP(i, N) cin >> t[i];
	REP(i, N) cin >> v[i];

	double T = 0;
	REP(i, N) T += t[i];
	vector<double> houra(2*T+1);

	REP(j, 2*T+1){
		ll tmp = 0;
		double mi = 1010101010;
		double place = ((1.0*j)/2);
		REP(i, N){
			double val;
			if(place<=tmp){
				val = v[i]+(tmp-place);
			}
			if(tmp<place && place<=tmp+t[i]){
				val = v[i];
			}
			if(place>tmp+t[i]){
				val = v[i]+(place-tmp-t[i]);
			}
			mi = min(mi, val);
			tmp += t[i];
		}
		double k = place;
		mi = min(mi, k);
		mi = min(mi, T-k);
		houra[j] = mi;
	}
	//vprint(houra);
	double res = 0.0;
	REP(i, 2*T){
		res += 1.0*(houra[i] + houra[i+1])/4.0;
	}
	printf("%.5f\n", res);
    return 0;
}
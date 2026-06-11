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
	vector<ll> X(N), Y(N);
	REP(i, N) cin >> X[i] >> Y[i];

	bool flag = true;
	int oe = (abs(X[0]) + abs(Y[0]))%2;
	ll ma = 0;
	REP(i, N){
		if (ma < abs(X[i]) + abs(Y[i])) ma = abs(X[i]) + abs(Y[i]);
		if (oe != (abs(X[i]) + abs(Y[i]))%2) flag = false;
	}
	if(!flag){
		cout << -1 << endl;
		return 0;
	}

	vector<ll> ds;
	for(int i=30;i>=0;i--) ds.push_back(1<<i);
	if(oe==0) ds.push_back(1);
	cout << ds.size() << endl;
	REP(i, ds.size()) cout << ds[i] << " ";
	cout << endl;

	REP(i, N){
		ll xdir, ydir;
		ll xsum = 0;
		ll ysum = 0;
		ll Z = X[i] + Y[i];
		ll W = X[i] - Y[i];
		REP(j, ds.size()){
			if(xsum<=Z){
				xdir = 1;
				xsum += ds[j];
			}else{
				xdir = -1;
				xsum -= ds[j];
			}
			if(ysum<=W){
				ydir = 1;
				ysum += ds[j];
			}else{
				ydir = -1;
				ysum -= ds[j];
			}
			if(xdir==1 && ydir==1) cout << "R";
			else if(xdir==1 && ydir==-1) cout << "U";
			else if(xdir==-1 && ydir==1) cout << "D";
			else if(xdir==-1 && ydir==-1) cout << "L";
		}
		cout << endl;
	}
    return 0;
}
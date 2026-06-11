#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//infinity
#define INTINF 2000000000
#define LONGINF 2000000000

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
	int n; cin >> n;
	long long a[n];
	REP(i, n) cin >> a[i];
	sort(a, a+n);

	int high = lower_bound(a, a+n, a[n-1]/2) - a;

	if(high == 0){
		cout << a[n-1] << " " << a[high] << endl;
		return 0;
	}

	if(high == n-1){
		cout << a[n-1] << " " << a[high-1] << endl;
		return 0;
	}

	int hh = a[n-1] - a[high];
	int ll = a[high-1];
	if(hh > ll){
		cout << a[n-1] << " " << a[high] << endl;
	}else{
		cout << a[n-1] << " " << a[high-1] << endl;
	}
	return 0;
}

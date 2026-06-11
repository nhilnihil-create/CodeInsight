
#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)


int main() {

	int n; cin >> n;

	vector<int> a(n);

	int mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		mx = max(mx, a[i]);

		a[i] = 2 * a[i];
	}


	int ans = 1<<31-1;
	int diff = 1 << 31 - 1;
	for (int i= 0; i < n; i++) {
		if (diff >= abs(mx - a[i])) {
			diff = abs(mx - a[i]);
			ans = a[i] / 2;
		}
	}

	cout << mx <<" "<< ans << endl;

	return 0;
}
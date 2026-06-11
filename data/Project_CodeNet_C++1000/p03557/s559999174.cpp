#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>


using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define Rep(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える


int main() {
	int n;
	cin >> n;

	vector<ll> a(n), b(n), c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];

	ll count = 0;

	sort(all(a));
	sort(all(b));
	sort(all(c));

	//jを固定するとa[i] < b[j] && b[j] < c[k]　なるi, k の積ikが部分解
	rep(j, n) {
		ll key = b[j];

		//itr_a はb[j] <= a[i] なるmin_iだからそれより右はすべてa[i] < b[j]
		ll itr_a = lower_bound(all(a), key) - a.begin();
		ll itr_b = upper_bound(all(c), key) - c.begin();

		count += itr_a * (n - itr_b);
	}

	cout << count << endl;
}
#include <bits/stdc++.h>
 
#define jyldam ios_base::sync_with_stdio;cin.tie(NULL);cout.tie(NULL);

#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define sz size()
#define fi first
#define se second
 
#define cmp_all(x) (x).begin(), (x).end(), cmp
#define batr ONLINE_JUDGE
#define all(x) (x).begin(),(x).end()
#define skip continue
 
using namespace std;

typedef long long ll;
typedef long double ld;
 
const int N = 1e6 + 17, maxN = 4 * N, D = 1e3 + 17, mod = 1e9 + 7;

ll a, b, c;

int main () {
	jyldam;
	cin >> a >> b >> c;
	if (a + b + 1 >= c) {
		cout << b + c;
	}
	else {
		cout << b + (a + b + 1);
	}
	return 0;
}
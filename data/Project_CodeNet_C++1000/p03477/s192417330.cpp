#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int lef = a + b;
	int rig = c + d;

	if (lef > rig) {
		cout << "Left\n";
	}
	else if (lef < rig) {
		cout << "Right\n";
	}
	else {
		cout << "Balanced\n";
	}

	return 0;
}
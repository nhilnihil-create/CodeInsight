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
	int t;
	cin >> t;
	
	int a = t / 100;
	int b = t % 100;


	
	string ans;

	if (a > 12) {
		if (1 <= b && b <= 12) {
			ans = "YYMM";
		}
		else {
			ans = "NA";
		}
	}
	else if (1 <= a && a <= 12) {
		if (1 <= b && b <= 12) {
			ans = "AMBIGUOUS";
		}
		else {
			ans = "MMYY";
		}
	}
	else {
		if (1 <= b && b <= 12) {
			ans = "YYMM";
		}
		else {
			ans = "NA";
		}
	}
	cout << ans << endl;

	return 0;
}
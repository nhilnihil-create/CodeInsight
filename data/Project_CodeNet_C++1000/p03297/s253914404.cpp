#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<random>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define int long long
#define inf 1145141919
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
typedef pair<int, P> PP;
struct edge { int to, cost; };
int gcd(int a, int b) {
	if (!b)return a;
	return gcd(b, a%b);
}
signed main() {
	int t; cin >> t;
	rep(x, t) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (b > a)cout << "No" << endl;
		else if (b > d)cout << "No" << endl;
		else if (b <= c)cout << "Yes" << endl;
		else {
			int G = gcd(b, d);
			a %= G;
			int l = b-(G-a)%G;
			if (l == b)l -= G;
			if (l > c)cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}
}
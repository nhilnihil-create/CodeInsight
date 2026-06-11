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
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
typedef pair<int, P> PP;
struct edge { int to, cost; };

signed main() {
	int n; cin >> n;
	if (n == 3) {
		puts("2 5 63");
	}
	else if (n == 4) {
		puts("2 5 20 63");
	}
	else {
		int a = 1, b = 2, c = 1, d = 0;
		for (int i = 5; i <= n; i++) {
			if (i % 8 == 5)d++;
			else if (i % 8 == 6)d++;
			else if (i % 8 == 7) {
				a++; c++; d--;
			}
			else if (i % 8 == 0)d++;
			else if (i % 8 == 1)d++;
			else if (i % 8 == 2) {
				a++; c++; d--;
			}
			else if (i % 8 == 3)d++;
			else {
				b += 2;
				d--;
			}
		}
		rep(i, a) {
			if (i)cout << ' ';
			cout << 6 * i + 2;
		}
		rep(i, b)cout << ' ' << 6 * i + 3;
		rep(i, c)cout << ' ' << 6 * i + 4;
		rep(i, d)cout << ' ' << 6 * i + 6;
		cout << endl;
	}
}
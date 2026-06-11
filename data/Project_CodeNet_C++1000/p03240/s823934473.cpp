#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll x[110], y[110], h[110];
int main()
{
	int N; cin >> N;
	int point = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] != 0)  point = i;
	}
	for (int X = 0; X <= 100; X++) {
		for (int Y = 0; Y <= 100; Y++) {
			ll H = h[point] + abs(x[point] - X) + abs(y[point] - Y);
			bool ok = true;
			for (int i = 0; i < N; i++) {
				if (h[i] != max(H - abs(x[i] - X) - abs(y[i] - Y), 0ll)) {
					ok = false;
						break;
				}
			}
			if (ok) {
				cout << X << " " << Y << " " << H << endl;
				return 0;
			}
		}
	}
}

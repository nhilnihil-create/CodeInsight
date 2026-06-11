#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	vector<vector<int>> cl(3);
	rep(i, 3) {
		rep(j, 3) {
			int c;
			cin >> c;
			cl[i].push_back(c);
		}
	}
	rep(a1, 101) {
		rep(a2, 101) {
			rep(a3, 101) {
				int b1 = -1, b2 = -1, b3 = -1;
				int pb1 = -1, pb2 = -1, pb3 = -1;
				bool isOK = true;
				rep(i, 3)
				{
					int a = 0;
					if (i == 0)
					{
						a = a1;
					}
					else if (i == 1) {
						a = a2;
					}
					else
					{
						a = a3;
					}
					b1 = cl[i][0] - a;
					b2 = cl[i][1] - a;
					b3 = cl[i][2] - a;
					if (i != 0 && !(pb1 == b1 && pb2 == b2 && pb3 == b3)) {
						isOK = false;
					}
					pb1 = b1;
					pb2 = b2;
					pb3 = b3;
				}
				if (isOK) {
					cout << "Yes" << endl;
					system("pause");
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}


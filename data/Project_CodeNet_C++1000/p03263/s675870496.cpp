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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int a[510][510];
int main()
{
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	vector<vector<int>> V;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W - 1; j++) {
			if (a[i][j] % 2 == 1) {
				cnt++;
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				v.push_back(i);
				v.push_back(j + 1);
				V.push_back(v);
				a[i][j]--;
				a[i][j + 1]++;
			}
		}
	}
	for (int i = 0; i < H - 1; i++) {
		if (a[i][W - 1] % 2 == 1) {
			cnt++;
			vector<int> v;
			v.push_back(i);
			v.push_back(W - 1);
			v.push_back(i + 1);
			v.push_back(W - 1);
			V.push_back(v);
			a[i][W - 1]--;
			a[i + 1][W - 1]++;
		}
	}
	cout << cnt << endl;
	for (vector<int> v : V) {
		for (int j = 0; j < v.size(); j++) {
			if (j != 0) cout << " ";
			cout << v[j] + 1;
		}
		cout << endl;
	}
}
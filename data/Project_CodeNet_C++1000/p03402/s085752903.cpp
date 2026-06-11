#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdbool.h>
#include<math.h>
#include<sstream>
#include<math.h>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<bitset>
typedef long long ll;
#define N (1000000000+7)
#define INF 1e10
#define Length 80000
using namespace std;
typedef pair<ll, ll> P;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool used[110];

bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
	return a.first * a.first + a.second * a.second > b.first*b.first + b.second * b.second;
}

void solve(int n) {
	vector<pair<int, int>>p(n), q(n);
	for (int i = 0;i < n;i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0;i < n;i++) {
		cin >> q[i].first >> q[i].second;
	}
	int dist = Length, flag = 0;
	int ans = 0;
	sort(p.begin(), p.end());
	for (int i = 0;i < n;i++) {
		dist = Length;
		flag = 0;
		for (int j = 0;j < n;j++) {
			if (!used[j]) {
				int x = q[j].first - p[i].first;
				int y = q[j].second - p[i].second;
				if ((x > 0) && (y > 0) && y < dist) {
					dist = y;
					flag = j;
				}
			}
		}
		if (dist < Length) {
			ans++;
			used[flag] = true;
		}
	}
	cout << ans << endl;
}

char board[110][110];
	
int main(void){
	int a, b, parity = 0;
	cin >> a >> b;
	cout << 100 << " " << 100 << endl;
	if (a == 1) {
		while (parity <= 100) {
			parity++;
			for (int i = 1;i <= 100;i++) {
				if (b > 0) {
					if (i & 1) {
						board[parity][i] = '.';
					}
					else {
						board[parity][i] = '#';
						b--;
					}
				}
				else {
					board[parity][i] = '.';
				}
			}
			parity++;
			for (int i = 1;i <= 100;i++)board[parity][i] = '.';
		}
		for (int i = 1;i <= 100;i++) {
			for (int j = 1;j <= 100;j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		return 0;
	}
	while (a > 1) {
		parity++;
		for (int i = 1;i <= 100;i++) {
			if (a > 1) {
				if (i & 1) {
					board[parity][i] = '.';
					a--;
				}
				else {
					board[parity][i] = '#';
				}
			}
			else {
				board[parity][i] = '#';
			}
		}
		parity++;
		for (int i = 1;i <= 100;i++)board[parity][i] = '#';
	}
	parity++;
	for (int i = 1;i <= 100;i++)board[parity][i] = '.';
	b--;
	if (b == 0) {
		parity++;
		for (int i = parity;i <= 100;i++) {
			for (int j = 1;j <= 100;j++)board[i][j] = '.';
		}
		for (int i = 1;i <= 100;i++) {
			for (int j = 1;j <= 100;j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		return 0;
	}
	while (parity<=100) {
		parity++;
		for (int i = 1;i <= 100;i++) {
			if (b > 0) {
				if (i & 1) {
					board[parity][i] = '.';
				}
				else {
					board[parity][i] = '#';
					b--;
				}
			}
			else {
				board[parity][i] = '.';
			}
		}
		parity++;
		for (int i = 1;i <= 100;i++)board[parity][i] = '.';
	}
	for (int i = 1;i <= 100;i++) {
		for (int j = 1;j <= 100;j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}
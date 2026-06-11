#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
int N, M;
vector<pair<int, int>> E[201010];
vector<pair<int, int>> EE[201010];
int vis[201010], col[201010];
//---------------------------------------------------------------------------------------------------
#define no "No"
#define yes "Yes"
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
 
string solve() {
	rep(i, 0, N) if (!vis[i]) {
		col[i] = 0;
		vis[i] = 1;
		queue<int> que;
		que.push(i);
		while (!que.empty()) {
			int q = que.front(); que.pop();
 
			fore(p, E[q]) {
				if (vis[p.first]) {
					if (col[q] + p.second != col[p.first]) return no;
				}
				else {
					col[p.first] = col[q] + p.second;
					vis[p.first] = 1;
					que.push(p.first);
				}
			}
 
			fore(p, EE[q]) {
				if (vis[p.first]) {
					if (col[q] - p.second != col[p.first]) return no;
				}
				else {
					col[p.first] = col[q] - p.second;
					vis[p.first] = 1;
					que.push(p.first);
				}
			}
		}
	}
 
	return yes;
}
//---------------------------------------------------------------------------------------------------
int main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		E[a].push_back({ b, c });
		EE[b].push_back({ a, c });
	}
	cout << solve() << endl;
 
	return 0;
}
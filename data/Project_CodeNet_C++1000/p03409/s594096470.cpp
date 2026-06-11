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
	int ans = 0;
	sort(q.begin(), q.end());
	for (int i = 0;i < n;i++) {
		int dist = -1;
		int flag = 0;
		for (int j = 0;j < n;j++) {
			if (!used[j]) {
				int x = q[i].first - p[j].first;
				int y = q[i].second - p[j].second;
				if ((x > 0) && (y > 0) && p[j].second > dist) {
					dist = p[j].second;
					flag = j;
				}
			}
		}
		if (dist > -1) {
			ans++;
			used[flag]=true;
		}
	}
	cout << ans << endl;
}
	
int main(void){
	int n;
	cin >> n;
	solve(n);
	return 0;
}
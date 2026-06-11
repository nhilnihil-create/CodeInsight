#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 200011;
int n,m;
char input[N];
bool ab[N];
vector<int> v[N][2];

bool imp[N];

int cnt;
int visited[N];
bool dfs(bool prev, int x) {
	if(imp[x]) return false;
	if(visited[x] == cnt) return true;
	visited[x] = cnt;

	bool cur = ab[x];
	
	for(int i=0; i<sz(v[x][!prev]); i++) {
		if(dfs(cur, v[x][!prev][i])) return true;
	}

	imp[x] = true;
	return false;
}

int main(void) {
	scanf("%d%d", &n, &m);
	scanf("%s", input);
	for(int i=0; i<n; i++) ab[i+1] = (input[i]=='A');

	int x, y;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		v[x][ab[y]].push_back(y);
		v[y][ab[x]].push_back(x);
	}

	for(int i=1; i<=n; i++) {
		cnt++;

		if(dfs(0,i) && dfs(1,i)) {
			visited[i] = 0;
			if(dfs(1,i)) {
				printf("Yes");
				return 0;
			}
		}
	}

	printf("No");
}

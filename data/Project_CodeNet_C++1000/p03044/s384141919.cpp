#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

vector<pair<int, int> > graph[100001];
int color[100001];
bool visited[100001];

void coloring(int now, int col){
	visited[now] = true;
	color[now] = col;
	for (auto x : graph[now]){
		if (!visited[x.first]){
			if (x.second % 2){
				coloring(x.first, (col+1)%2);
			}else{
				coloring(x.first, col);
			}
		}
	}
	return;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	coloring(1, 0);
	for (int i = 1; i <= n; i++){
		cout << color[i] << endl;
	}
	return 0;
}
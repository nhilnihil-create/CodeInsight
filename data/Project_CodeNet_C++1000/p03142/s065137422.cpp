#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> e(n);
	vector<int> d(n);
	for(int i = 0;i < n;i++)d[i] = INF;

	vector<int> in_deg(n,0);
	for(int i = 0;i < n - 1 + m;i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		e[a].push_back(b);
		in_deg[b]++;
	}

	int s;
	for(int i = 0;i < n;i++){
		if(in_deg[i] == 0)s = i;
	}

	d[s] = 0;
	vector<int> par(n,0);

	queue<int> que;
	que.push(s);
	while(que.size()){
		int now = que.front();
		que.pop();
		for(int next:e[now]){
			in_deg[next]--;
			if(in_deg[next] == 0){
				que.push(next);
				par[next] = now + 1;
			}
		}
	}

	for(int i = 0;i < n;i++){
		cout << par[i] << endl;
	}
}

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > graph(10001);
	int connectNum[10001] = {};
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		connectNum[a]++;
		connectNum[b]++;
	}
	int c[10001];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	sort(c, c + n);

	queue<int> qu;
	int cnt = 0;
	vector<int> ans(10001, -1);
	for(int i = 0; i < n; i++){
		if(connectNum[i] == 1){
			qu.push(i);
			ans[i] = c[cnt];
			cnt++;
		}
	}

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		for(int j = 0; j < graph[now].size(); j++){
			int next = graph[now][j];
			connectNum[next]--;
			if(connectNum[next] == 1){
				ans[next] = c[cnt];
				cnt++;
				qu.push(next);

			}
		}
	}
	cout << accumulate(c, c + n - 1, 0) << endl;
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}
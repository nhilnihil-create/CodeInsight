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
#include <complex>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	vector<vector<int> > graph(n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> c;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		c.push_back(tmp);
	}
	sort(c.begin(), c.end());
	queue<int> qu;
	vector<bool> ischecked(n, false);
	vector<int> ans(n);
	qu.push(0);
	ischecked[0] = true;
	for(int i = n - 1; i >= 0; i--){
		int now = qu.front();
		qu.pop();
		ans[now] = c[i];
		for(int j = 0; j < graph[now].size(); j++){
			int next = graph[now][j];
			if(!ischecked[next]){
				ischecked[next] = true;
				qu.push(next);
			}
		}
	}
	long long int m = accumulate(c.begin(), c.end(), 0) - c[n - 1];
	cout << m << endl;
	for(int i = 0; i < n; i++){
		cout << ans[i];
		if(i == n - 1) cout << endl;
		else cout << " ";
	}
}
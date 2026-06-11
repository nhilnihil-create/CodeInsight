//msolutions2019_d.cpp
//Sun Jun 28 12:39:28 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	vector<int> G[n];
	for (int i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int c[n];
	for (int i=0;i<n;i++){
		cin >> c[i];
	}
	sort(c,c+n,greater<int>());

	queue<int> q;
	q.push(0);
	int visited[n];
	fill(visited,visited+n,-1);
	visited[0] = c[0];
	int ans = 0;
	int ccount = 1;
	while(!q.empty()){
		int tmp = q.front();q.pop();
		for (int i=0;i<G[tmp].size();i++){
			int next = G[tmp][i];
			if (visited[next]==-1){
				ans += c[ccount];
				q.push(next);
				visited[next] = c[ccount];
				ccount++;
			}
		}
	}

	cout << ans << endl;
	for (int i=0;i<n;i++){
		cout << visited[i] << " ";
	}
	printf("\n");
//	printf("%.4f\n",ans);
}
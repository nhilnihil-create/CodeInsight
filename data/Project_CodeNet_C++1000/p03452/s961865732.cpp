#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
vector <pii> neigh[100003];
int dist[100003];
int main() {
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x,y,l;
		cin>>x>>y>>l;
		neigh[x].push_back(pii(y,l));
		neigh[y].push_back(pii(x,-l));
	}
	for (int i=1; i<=n; i++) dist[i]=1e9;
	for (int i=1; i<=n; i++)
		if (dist[i]==1e9) {
			queue <int> q;
			q.push(i);
			dist[i]=0;
			while (!q.empty()) {
				int x=q.front();
				q.pop();
				for (int i=0; i<neigh[x].size(); i++) {
					int p=neigh[x][i].first;
					int di=neigh[x][i].second;
					if (dist[p]!=1e9) {
						if (dist[x]+di!=dist[p]) {
							puts("No");
							return 0;
						}
					} else {
						dist[p]=dist[x]+di;
						q.push(p);
					}
				}
			}
		}
	puts("Yes");
	return 0;
}
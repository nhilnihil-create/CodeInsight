#include <bits/stdc++.h>
#define maxn 586

using namespace std;

int n, m;
int a[maxn][maxn];
vector<pair<int, int> > v;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < m;j++){
			if(a[i][j] & 1){
				a[i][j]--, a[i][j + 1]++;
				v.push_back({i, j});
			}
		}
	}
	for(int i = 1;i < n;i++){
		if(a[i][m] & 1){
			a[i][m]--, a[i + 1][m]++;
			v.push_back({i, m});
		}
	}
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++){
		if(v[i].second == m) printf("%d %d %d %d\n", v[i].first, v[i].second, v[i].first + 1, v[i].second);
		else printf("%d %d %d %d\n", v[i].first, v[i].second, v[i].first, v[i].second + 1);
	}
}

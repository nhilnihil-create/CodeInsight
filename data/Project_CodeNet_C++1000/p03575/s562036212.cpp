#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n,m;
	cin >> n >> m;
	const int INF = 1<<10;
	vector<vector<int>> d(n,vector<int>(n,INF));
	vector<vector<int>> g(m,vector<int>(2));
	REP(i,m){
		int a,b;
		cin >> a >> b;
		a--; b--;
		g[i][0] = a;
		g[i][1] = b;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	
	int ans = 0;
	REP(i,m){
		queue<int> q;
		vector<int> visited(n,0);
		q.push(0);
		visited[0] = 1;
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			REP(j,n){
				if(now==j) continue;
				if((now==g[i][0]&&j==g[i][1]) || (now==g[i][1]&&j==g[i][0])) continue;
				
				if(d[now][j]==1 && visited[j]==0){
					visited[j] = 1;
					q.push(j);
				}
			}
		}
		
		int sum = 0;
		REP(i,n) sum+=visited[i];
		if(sum!=n) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
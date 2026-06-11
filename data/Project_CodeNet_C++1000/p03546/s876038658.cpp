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
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int d[10][10];

void warshall_floyd(int n){
	REP(k,n){
		REP(i,n){
			REP(j,n){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
}

int main(){
	int h,w;
	cin >> h >> w;
	REP(i,10) REP(j,10) cin >> d[i][j];
	vector<vector<int>> a(h, vector<int>(w));
	REP(i,h) REP(j,w) cin >> a[i][j];
	
	warshall_floyd(10);
	
	int ans=0;
	REP(i,h) REP(j,w){
		if(a[i][j]==-1) continue;
		ans += d[a[i][j]][1];
	}
	cout << ans << endl;
	
	return 0;
}
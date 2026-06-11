//q062.cpp
//Sat Aug 29 18:58:10 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 1e8
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int d[10][10];

void warshall_floyd(){
	for (int k=0;k<10;k++){
		for (int i=0;i<10;i++){
			for (int j=0;j<10;j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}

int main(){
	int h,w;
	cin >> h >> w;

	rep(i,10)rep(j,10) cin >> d[i][j];

	warshall_floyd();

	int ans = 0;
	rep(i,h)rep(j,w){
		int x;
		cin >> x;
		if(x==-1)continue;
		ans += d[x][1];
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}
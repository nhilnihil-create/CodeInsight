#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000;
ll d[10][10];

void init(){
	rep(i,10){
		rep(j,10) d[i][j] = INF;
		d[i][i] = 0;
	}
}

void warshall_floyd(int n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if( d[i][k] == INF || d[k][j] == INF){
					// do nothing
				}else{
					d[i][j] = min(d[i][j],d[i][k] + d[k][j]);	
				}
			}
		}
	}
}


int main()
{
	init();
	int h,w;
	cin>>h>>w;
	rep(i,10){
		rep(j,10){
			cin>>d[i][j];
		}
	}
	warshall_floyd(10);
	ll ans = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			int c;
			cin>>c;
			if( c == -1 || c == 1){
				continue;
			}else{
				ans += d[c][1];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


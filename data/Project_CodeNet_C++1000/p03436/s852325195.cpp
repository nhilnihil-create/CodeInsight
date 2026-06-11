//q033.cpp
//Sat Aug 15 14:51:36 2020

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
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int h,w;
	cin >> h >> w;

	string s[h];
	rep(i,h) cin >> s[i];

	queue<P> q;
	q.push(P(0,0));

	int movex[4] = {0,1,0,-1};
	int movey[4] = {1,0,-1,0};

	int d[h][w];
	int whitenum = 0;
	rep(i,h)rep(j,w){
		d[i][j] = -1;
		if (s[i][j]=='.'){
			whitenum++;
		}
	}
	d[0][0] = 1;
	while (!q.empty()){
		P cur = q.front();q.pop();
		rep(i,4){
			P next = P(cur.first+movex[i],cur.second+movey[i]);
			if (next.first<0 || next.first>h-1 ||
				next.second<0 || next.second>w-1 ||
				d[next.first][next.second]!=-1 ||
				s[next.first][next.second]=='#'){
				continue;
			}
			d[next.first][next.second] = d[cur.first][cur.second]+1;
			q.push(next);
			if (next.first==h-1 && next.second==w-1){
				cout << whitenum-d[next.first][next.second] << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;

}
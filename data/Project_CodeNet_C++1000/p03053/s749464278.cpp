#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
int n , m , maxi , dx[5] , dy[5];
char grid[2000][2000];
bool cek[2000][2000];
typedef pair<pair<int , int>,int> iii;
iii a;
queue<iii>q;
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> grid[i][j];
			if(grid[i][j] == '#'){
				q.push(mp(mp(i , j) , 0));
			}
		}
	}
	dx[1] = 1;
	dx[2] = -1;
	dx[3] = 0;
	dx[4] = 0;
	dy[1] = 0;
	dy[2] = 0;
	dy[3] = 1;
	dy[4] = -1;
	maxi = 0;
	while(!q.empty()){
		a = q.front();
		int x = a.fi.fi;
		int y = a.fi.se;
		int z = a.se;
		maxi = max(maxi , z);
		q.pop();
		if(cek[x][y])continue;
		cek[x][y] = true;
		for(int i = 1 ; i <= 4 ; i++){
			if(x + dx[i] < 1 || x + dx[i] > n || y + dy[i] < 1  || y + dy[i] > m)continue;
			q.push(mp(mp(x + dx[i], y + dy[i]) , z + 1));
		}
	}
	maxi -= 1;
	if(maxi < 0)cout << 0 << endl;
	else cout << maxi << endl;
}
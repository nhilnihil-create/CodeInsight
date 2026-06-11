#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
const int MxN = 10005 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
# define RFOR(i,a,b) for(int i = a ; i >= b ; --i)

/* VARIABLES */
int h,w ; 
char a[50][50] ;
int ans[50][50] ;
int blacks=0;  
bool vis[50][50] ; 
/* END OF VARIABLES */

bool isvalid(int x,int y) {
	if(x < 0 || x >= h || y < 0 || y >= w)
		return false ;
	return true ; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  

	cin >> h >> w ;  
 
	FOR(i,0,h) {
		FOR(j,0,w){
			cin >> a[i][j] ; 
			if(a[i][j] == '#')
				blacks++;
		}
	}
	memset(ans,1e8,sizeof(ans)) ; 
	vis[0][0] = true ; 
	list<PII> q ; 
	q.push_back({0,0}) ; 
	int cnt = 0 ; 
	ans[0][0] = 0 ; 
	while(!q.empty()) {
		PII u = q.front() ; 
		q.pop_front() ; 
		for(int dx : {-1,0,1,0}) {
			for(int dy : {-1,0,0,1}) {
				if(abs(dx) == abs(dy))
					continue ; 
				int new_x = u.first + dx ; 
				int new_y = u.second + dy ; 
				if(isvalid(new_x, new_y) && !vis[new_x][new_y] && a[new_x][new_y] == '.') {
					vis[new_x][new_y] = true ; 
					ans[new_x][new_y] =  1 + ans[u.first][u.second];
					if(new_x == h-1  && new_y == w-1) {
						cout << h*w - blacks - ans[h-1][w-1] - 1 ;
						return 0 ;
					} 
					q.push_back({new_x,new_y}) ; 
				}
			}
		}
	}
	cout << -1 ; 
	return 0 ; 
}


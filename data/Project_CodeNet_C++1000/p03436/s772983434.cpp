#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


vector<string> f(50);
int dist[60][60];

int main(){
    int H,W;
    int cnt = 0;
    cin >> H >> W;
    rep(i,H) {
	string s;
	cin >> s;
	f[i] = s;
    }

    rep(i,H) {
	rep(j,W) {
	    if(f[i][j] == '.') cnt++;
	}
    }
    cnt -= 2;

    queue<P> q;
    f[0][0] = '#';
    q.push(make_pair(0,0));
    while(!q.empty()) {
	int y = q.front().first;
	int x = q.front().second;
	q.pop();
	rep(i,4) {
	    int ny = y + dy[i];
	    int nx = x + dx[i];
	    if(ny >=0 && ny < H && nx >= 0 && nx < W && f[ny][nx] == '.' && dist[ny][nx] == 0) {
		q.push(make_pair(ny,nx));
		dist[ny][nx] = dist[y][x] + 1;
	    }
	}
    }
    // rep(i,H) {
    // 	rep(j,W) cout << dist[i][j];
    // 	cout << endl;
    // }

    if(dist[H-1][W-1] == 0) cout << -1 << endl;
    else cout << cnt - dist[H-1][W-1] + 1 << endl;
    

    
    
    return 0;
}


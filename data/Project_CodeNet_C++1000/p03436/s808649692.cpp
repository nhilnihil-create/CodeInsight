#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <tuple>
#include <cctype>
#include <ctype.h>
#include <set>
#include <sstream>
#include <time.h>
#include <numeric>
using namespace std;
//#define int long long
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define l1 list[index]
#define l2 list[index - 1]
#define l3 list[index + 1]
#define iif(i,j) ((i<0 && j<0) || (i>0 && j>0)) ? true : false 
typedef long long ll;
//typedef pair<int, int>pint;
//typedef vector<int>vint;
//typedef vector<pint>vpint;
//typedef pair<pint, int> P1;
//typedef pair<int, pint> P2;
//typedef pair<pint, pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD = 1000000007;
const ll INF = 1e18;
const double PI = 3.14159265359;
int ca[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

typedef pair<int, int> P;

int R, C, sy = 0, sx = 0, gy , gx;
vector<string>slist;
int blackCnt = 0;



int main(void) {
	
	cin >> R >> C;

	gy = R - 1; gx = C - 1;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		slist.push_back(s);
	}

	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			if (slist[i][j] == '#')blackCnt++;

	vector<vector<int>>mat(R, vector<int>(C, 999999));
	int yy[4] = { -1, 0, 1, 0 };
	int xx[4] = { 0, 1, 0, -1 };
	
	queue<P> qlist;
	mat[sy][sx] = 0;
	qlist.push(P(sy, sx));

	while ( qlist.size() > 0 )
	{
		P p = qlist.front();
		qlist.pop();

		if (p.first == gy && p.second == gx)break;

		for (int i = 0; i < 4; i++) {
			int ny = p.first + yy[i];
			int nx = p.second + xx[i];

			if (ny >= 0 && ny < R && 0 <= nx && nx < C && slist[ny][nx] == '.' && mat[ny][nx] == 999999) {
				mat[ny][nx] = mat[p.first][p.second] + 1;
				qlist.push(P(ny, nx));
			}

		}

	}

	if (mat[gy][gx] == 999999) {
		cout << -1 << endl;
	}
	else {
		cout << R * C - (mat[gy][gx] + 1) - blackCnt << endl;
	}

	return 0;
}
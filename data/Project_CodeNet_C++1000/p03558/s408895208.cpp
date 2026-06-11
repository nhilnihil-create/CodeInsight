#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <string.h>
#include <math.h>
typedef long long ll;
#define INF			100000
#define MAX(x, y)	(((x) > (y))? (x) : (y))
#define MIN(x, y)	(((x) < (y))? (x) : (y))
#define ABS(x)		(((x) < 0)? (-1*(x)) : (x))
#define REP(i,x,y)	for (int (i)=(x);(i)<(y);(i)++)
#define REP_(i,x,y)	for ((i)=(x);(i)<(y);(i)++)
#define MEMCLR(X)	memset((X),0,sizeof((X)))

using namespace std;
typedef pair<int, int> Point;
typedef vector<vector<Point>> Graph;

int K;
int d[INF];
deque<int> q;

int main() {
	
	cin >> K;
	
	REP(i,0,K) d[i] = INF;
	d[1] = 1;
	q.push_back(1);
	
	while ( !q.empty() ) {
		int x = q.front();q.pop_front();
		int a = (x+1) % K, b = (10*x) % K;
		int aa = d[x]+1, bb = d[x];
		
		if ( aa < d[a] ) d[a] = aa, q.push_back(a);
		if ( bb < d[b] ) d[b] = bb, q.push_back(b);
	}

	cout << d[0];

	return 0;
}

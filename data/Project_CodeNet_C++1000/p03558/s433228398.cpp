#include <bits/stdc++.h>
using namespace std;

#define N 100000

int dist[N];

int main()
{
	int ans = 0;
	int k;

	cin >> k;

	for( int i = 0; i < N; i++ ) {
		dist[i] = INT32_MAX;
	}
	typedef pair< int, int> P;
	priority_queue<P> p;
	p.push( make_pair(-1, 1) );
	while( !p.empty() ) {
		int c = -p.top().first;
		int n = p.top().second;
		p.pop();
		if( dist[n] <= c ) {
			continue;
		}
		dist[n] = c;
		if( dist[(n + 1) % k] > c + 1) {
			p.push( make_pair(-(c + 1), (n + 1) % k) );
		}
		if( dist[(n * 10) % k] > c + 1) {
			p.push( make_pair(-c, (n * 10) % k) );
		}
	}
	ans = dist[0];

	cout << ans << endl;

	return 0;
}

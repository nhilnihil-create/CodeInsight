#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> g( N );
	for( int i = 0; i < N - 1; i++ ) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back( b );
		g[b].push_back( a );
	}
	vector<int> c( N );
	for( int i = 0; i < N; i++ ) {
		cin >> c[i];
	}

	sort( c.begin(), c.end(), greater<int>() );
	long long ans = 0;
	vector<int> d( N, -1 );
	queue<int> que;
	que.push( 0 );
	int i = 0;
	d[0] = c[i];
	i++;
	while( !que.empty() ) {
		int j = que.front();
		que.pop();
		for( int e : g[j] ) {
			if( d[e] >= 0 ) continue;
			d[e] = c[i];
			i++;
			que.push( e );
			ans += min( d[j], d[e] );
		}
	}

	cout << ans << endl;
	for( int i = 0; i < N; i++ ) {
		if( i ) cout << " ";
		cout << d[i];
	}
	cout << endl;
}

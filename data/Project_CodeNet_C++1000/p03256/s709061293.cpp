#include <bits/stdc++.h>
using namespace std;

#define N 100000*2
#define INF 1LL << 60

int n, m;
string s;
vector<int> g[N];

int numA[N];
int numB[N];
bool deleted[N];

void del( int i )
{
	if( deleted[i] ) {
		return;
	}
	deleted[i] = true;
	for( auto j : g[i] ) {
		if( deleted[j] ) {
			continue;
		}
		if( s[i] == 'A' ) {
			numA[j]--;
		}
		else {
			numB[j]--;
		}
		if( numA[j] == 0 || numB[j] == 0 ) {
			del( j );
		}
	}
}

int main()
{
	int a, b;

	cin >> n >> m;
	cin >> s;
	for( int i = 0; i < m; i++ ) {
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back( b );
		g[b].push_back( a );
		if( s[b] == 'A' ) {
			numA[a]++;
		}
		else {
			numB[a]++;
		}
		if( s[a] == 'A' ) {
			numA[b]++;
		}
		else {
			numB[b]++;
		}
	}

	for( int i = 0; i < n; i++ ) {
		if( numA[i] == 0 || numB[i] == 0 ) {
			del( i );
		}
	}
	int flag = 0;
	for( int i = 0; i < n; i++ ) {
		if( !deleted[i] ) {
			flag = 1;
		}
	}

	if( flag ) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

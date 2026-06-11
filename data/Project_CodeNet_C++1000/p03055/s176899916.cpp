#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()

vector< vector<int> > edge;
vector<bool> used;

pair<int, int> dfs( int v )
{
	int fMax = 0;
	int fMax_v = v;
	used[v] = true;
	for( auto to : edge[v] )
	{
		if( !used[to] )
		{
			used[to] = true;
			auto p = dfs( to );
			if( fMax < p.second + 1 )
			{
				fMax = p.second + 1;
				fMax_v = p.first;
			}
		}
	}
	return pair<int,int>( fMax_v, fMax );
}

int main()
{
	int n, m;
	cin >> n;
	m = n - 1;

	edge.assign(n,vector<int>());
	used.assign(n,false);
	REP( i, m )
	{
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back( b-1 );
		edge[b-1].push_back( a-1 );
	}

	fill( ALL(used), false );
	auto lon = dfs( 0 );
	//cout << lon.first << " " << lon.second << endl;
	fill( ALL(used), false );
	auto lonn = dfs( lon.first );
	//cout << lonn.first << " " << lonn.second << endl;

	cout << ( lonn.second % 3 == 1 ? "Second" : "First" ) << endl;

	return 0;
}
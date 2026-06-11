#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<pair<long long, int>>> c( N );
	for( int i = 0; i < M; i++ ) {
		int P;
		long long Y;
		cin >> P >> Y;
		P--;
		c[P].push_back( make_pair( Y, i ) );
	}

	vector<pair<int, string>> id;
	for( int i = 0; i < N; i++ ) {
		sort( c[i].begin(), c[i].end() );
		int y = 1;
		for( int j = 0; j < c[i].size(); j++ ) {
			int n;
			long long Y;
			tie( Y, n ) = c[i][j];
			char ch[16];
			sprintf( ch, "%06d%06d", i + 1, y );
			id.push_back( make_pair( n, string( ch ) ) );
			y++;
		}
	}
	sort( id.begin(), id.end() );
	for( int i = 0; i < id.size(); i++ ) {
		int n;
		string ans;
		tie( n, ans ) = id[i];
		cout << ans << endl;
	}
}

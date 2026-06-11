#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> s( M );
	vector<int> p( M );
	for( int i = 0; i < M; i++ ) {
		int k;
		cin >> k;
		for( int j = 0; j < k; j++ ) {
			int S;
			cin >> S;
			S--;
			s[i].push_back( S );
		}
	}
	for( int i = 0; i < M; i++ ) {
		cin >> p[i];
	}

	long long ans = 0;
	for( int mask = 0; mask < 1 << N; mask++ ) {
		int flag = 0;
		for( int i = 0; i < M; i++ ) {
			int cnt = 0;
			for( int j = 0; j < s[i].size(); j++ ) {
				int sw = s[i][j];
				if( mask >> sw & 1 ) cnt++;
			}
			if( cnt % 2 == p[i] ) continue;
			else {
				flag = 1;
				break;
			}
		}
		if( flag == 0 ) ans++;
	}

	cout << ans << endl;
}

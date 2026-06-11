#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> X( M );
	for( int i = 0; i < M; i++ ) {
		cin >> X[i];
	}

	int ans = 0;
	if( M > N ) {
		sort( X.begin(), X.end() );
		priority_queue<int> que;
		for( int i = 0; i < M - 1; i++ ) {
			que.push( X[i + 1] - X[i] );
		}
		ans = X[M - 1] - X[0];
		for( int i = 0; i < N - 1; i++ ) {
			int l = que.top();
			que.pop();
			ans -= l;
		}
	}

	cout << ans << endl;
}

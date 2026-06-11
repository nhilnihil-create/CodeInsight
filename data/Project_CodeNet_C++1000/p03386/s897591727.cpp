#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A, B, K;
	cin >> A >> B >> K;

	vector<long long> ans;
	long long a = A;
	for( int i = 0; i < K; i++ ) {
		if( a > B ) break;
		ans.push_back( a );
		a++;
	}
	long long b = B;
	for( int i = 0; i < K; i++ ) {
		if( count( ans.begin(), ans.end(), b ) ) break;
		ans.push_back( b );
		b--;
	}
	sort( ans.begin(), ans.end() );

	for( int i = 0; i < ans.size(); i++ ) {
		cout << ans[i] << endl;
	}
}

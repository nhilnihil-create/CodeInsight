#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> W( N );
	for( int i = 0; i < N; i++ )  {
		cin >> W[i];
	}

	string ans = "Yes";
	set<string> st;
	char c;
	for( int i = 0; i < N; i++ )  {
		if( i == 0 ) c = W[i][W[i].size() - 1];
		else if( st.count( W[i] ) || W[i][0] != c ) {
			ans = "No";
			break;
		}
		else c = W[i][W[i].size() - 1];
		st.insert( W[i] );
	}

	cout << ans << endl;
}

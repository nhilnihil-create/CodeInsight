#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int n = S.size();
	int num[3] = {0};
	for( int i = 0; i < n; i++ ) {
		if( S[i] == 'a' ) num[0]++;
		else if( S[i] == 'b' ) num[1]++;
		else num[2]++;
	}
	sort( num, num + 3 );
	string ans = "YES";
	if( num[2] - num[1] > 1 || num[1] - num[0] > 1 || num[2] - num[0] > 1 ) ans = "NO";

	cout << ans << endl;
}

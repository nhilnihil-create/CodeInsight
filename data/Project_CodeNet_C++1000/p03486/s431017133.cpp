#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;

	sort( s.begin(), s.end() );
	sort( t.begin(), t.end(), greater<char>() );
	string ans = "No";
	if( t > s ) ans = "Yes";

	cout << ans << endl;
}

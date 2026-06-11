#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string ans = S.substr( 0, S.size() - strlen("FESTIVAL") );

	cout << ans << endl;
}

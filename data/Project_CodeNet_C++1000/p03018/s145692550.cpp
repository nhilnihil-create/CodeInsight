#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string S;
	cin >> S;

	int N = S.size();
	long long ans = 0;
	int a = 0;
	for( int i = 0; i < N - 1; i++ ) {
		if( S[i] == 'A' ) a++;
		else if( S[i] == 'B' && S[i + 1] == 'C' ) {
			ans += a;
			i++;
		}
		else a = 0;
	}

	cout << ans << endl;
}

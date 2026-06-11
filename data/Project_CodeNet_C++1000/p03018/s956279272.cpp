#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string S;
	cin >> S;

	int N = S.size();
	string s;
	for( int i = 0; i < N; i++ ) {
		if( i + 1 < N && S[i] == 'B' && S[i + 1] == 'C' ) {
			s += 'D';
			i++;
		}
		else s += S[i];
	}
	int n = s.size();
	int a = 0;
	long long ans = 0;
	for( int i = 0; i < n; i++ ) {
		if( s[i] == 'A' ) a++;
		else if( s[i] == 'D' ) ans += a;
		else a = 0;
	}

	cout << ans << endl;
}

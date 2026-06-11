#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	long long K;
	cin >> S >> K;

	int n1 = 0;
	int N = S.size();
	
	for( int i = 0; i < N; i++ ) {
		if( S[i] == '1' ) n1++;
		else break;
	}
	char ans = '1';
	if( K > n1 ) ans = S[n1];

	cout << ans << endl;
}

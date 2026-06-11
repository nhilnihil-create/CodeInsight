#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;

	int N = S.size();
	string ans = "No";
	for( int k = 0; k < N; k++ ) {
		int flag = 0;
		for( int i = 0; i < N; i++ ) {
			if( S[(i + k) % N] != T[i] ) {
				flag = 1;
				break;
			}
		}
		if( flag == 0 ) {
			ans = "Yes";
			break;
		}
	}

	cout << ans << endl;
}

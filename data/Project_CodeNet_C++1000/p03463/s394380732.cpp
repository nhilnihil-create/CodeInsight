#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, A, B;
	cin >> N >> A >> B;

	int turn = 0;
	string ans;
	while( 1 ) {
		if( turn ) {
			if( B - 1 == A ) {
				if( B == N ) {
					ans = "Alice";
					break;
				}
				else {
					B++;
				}
			}
			else B--;
		}
		else {
			if( A + 1 == B ) {
				if( A == 1 ) {
					ans = "Borys";
					break;
				}
				else {
					A--;
				}
			}
			else A++;
		}
		turn = 1 - turn;
	}

	cout << ans << endl;
}

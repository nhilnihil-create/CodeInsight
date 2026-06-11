#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, K;

	cin >> N >> K;

	int A = 1;
	int i = 0;

	for( ; i < N ; ){

		A *= 2;

		i++;

			if( A > K )
			break;

		}

	cout << ( N - i ) * K + A <<endl;
	
	}
#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, A , j, k;

	k = 999;

	j = 0;

	cin >> N;

	for( int i = 0; i < N; i++){

	cin  >> A;

		while( A % 2 == 0){

			A = A / 2;

			j++;

			}

	if( j < k)

	k = j;
	
	j = 0;

	}

cout << k << endl;

}
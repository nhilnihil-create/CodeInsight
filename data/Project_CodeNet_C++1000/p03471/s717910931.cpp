#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int N, Y,i,j;
	cin >> N;
	cin >> Y;
	for ( i = 0; i <= N; i++) {
		for ( j = 0; j+i <= N; j++) {
			if (Y - (10000 * i) - (5000 * j) - (1000 * (N - i - j)) == 0) {
				if (i+j+(N-i-j)==N) {
					cout << i << " " << j << " " << (N - i - j) << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1 -1 -1" << endl;
	return 0;
}
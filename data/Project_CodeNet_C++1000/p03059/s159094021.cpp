#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int A, B, T;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> A >> B >> T;

	long long ans = 0;
	for(int t=A; t <= T; t += A){
		ans += B;
	}
	printf("%lld\n", ans);
	return 0;
}
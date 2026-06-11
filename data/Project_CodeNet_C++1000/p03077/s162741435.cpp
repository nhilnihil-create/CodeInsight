#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N, A, B, C ,D, E;
	long long S[5];

	cin >> N;
	cin >> A; S[0] = A;
	cin >> B; S[1] = B;
	cin >> C; S[2] = C;
	cin >> D; S[3] = D;
	cin >> E; S[4] = E;

	long long m = 1L<<60;
	long long t = 0;

	for(int i=0; i<5; i++){
		if(m > S[i]){
			m = S[i];
		}
		long long u = N - (t - i) * m;
		t += u / m + 1;
		if((u % m) == 0){
			t--;
		}
	}
	cout << t << endl ;
	return 0;
}
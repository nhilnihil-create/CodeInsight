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
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, x;
	cin >> N >>x;
	vector<LL> A;
	for(int i=0; i<N; i++){
		LL a; cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	int ans = 0;
	for(int i=0; i<N; i++){
		if(x >= A[i] && i<N-1){
			ans++;
			x -= A[i];
		}
		else if(x == A[i] && i==N-1){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
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
long long INF = (1LL<<62);
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	LL N = S.size();
	for(int i=N-1; i>=0; i--){
		if(S[i] == 'B'){
			S.pop_back();
		}
		else{
			break;
		}
	}
	N = S.size();
	LL ans = 0, c = N-1;
	for(int i=S.size()-1; i>=0; i--){
		if(S[i] == 'B'){
			ans += (c - i);
			c--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}


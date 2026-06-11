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

LL black[200002] = {0};
LL white[200002] = {0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	string S;
	cin >> N;
	cin >> S;

	while(true){
		if(S[S.size()-1] == '#'){
			S.pop_back();
		}
		else{
			break;
		}
	}

	int bfound = 0;
	string U;
	for(int i=0; i<S.size(); i++){
		if(S[i] == '#'){
			bfound = 1;
		}
		if(bfound){
			U.push_back(S[i]);
		}
	}
	LL w=0, b=0;
	for(int i=0; i<U.size(); i++){
		if(U[i] == '#'){
			b++;
		}
		else{
			w++;
		}
		black[i] = b;
		white[i] = w;
	}

	LL ans1 = (1LL<<62);
	for(int i=0; i<U.size(); i++){
		LL ul = black[i];
		LL ur = w - white[i];
		if(ans1 > ul + ur){
			ans1 = ul + ur;
		}
	}

	LL ans = min(min(b, w), ans1);
	printf("%lld\n", ans);
	return 0;
}


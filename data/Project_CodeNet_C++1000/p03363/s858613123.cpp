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

static LL P = 1000000007LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	cin >> N;
	vector<LL> A, S;
	map<LL, LL> M;
	A.push_back(0);
	S.push_back(0);
	for(int i=1; i<=N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
		LL s = S[i-1] + a;
		S.push_back(s);
		if(M.count(s) == 0){
			M[s] = 1;
		}
		else{
			M[s]++;
		}
	}
	LL ans = 0;
	for(auto itr = M.begin(); itr != M.end(); itr++){
		LL k = itr->first;
		LL v = itr->second;
		if(v > 1){
			LL w = v*(v-1);
			w = w/2;
			ans += w;
		}
		if(k == 0){
			ans += v; //先頭a0から当該項までの部分列を加算
		}
	}
	printf("%lld\n", ans);
	return 0;
}


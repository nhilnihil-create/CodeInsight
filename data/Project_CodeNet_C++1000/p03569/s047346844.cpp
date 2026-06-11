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
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);

int isKaibun(string s){
	int ret = 1;
	for(int i=0; i<s.size(); i++){
		if(s[i] != s[s.size()-1-i]){
			ret = 0;
			break;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S, T;
	cin >> S;

	for(int i=0; i<S.size(); i++){
		if(S[i] != 'x'){
			T.push_back(S[i]);
		}
	}

	if(isKaibun(S) == 1){
		printf("0\n");
		return 0;
	}
	if(isKaibun(T) == 0){
		printf("-1\n");
		return 0;
	}

	LL tl = T.size();
	LL m = tl/2;
	LL ls = -1, rs = -1, c = 0;
	for(int i=0; i<S.size(); i++){
		if(S[i] != 'x'){
			if(tl == 1){
				rs = i;
				break;
			}
			c++;
		}
		if(ls == -1 && c == m){
			ls = i;
		}
		if(rs == -1 && c == m+1){
			rs = i;
		}

	}

	if((tl % 2) == 1){
		ls = rs;
	}

	LL ans = 0;
	LL u = ls, v = rs;
	while(true){
		if(S[u] == S[v]){
			if(u == 0 && v == S.size()-1){
				break;
			}
			if(u > 0){
				u--;
			}
			else if(S[u] == 'x'){
				ans++;
			}
			if(v < S.size() - 1){
				v++;
			}
			else if(S[v] == 'x'){
				ans++;
			}
		}
		else{
			ans++;
			if(u == 0 && v == S.size()-1){
				break;
			}
			if(S[u] == 'x'){
				u--;
			}
			else{
				v++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}


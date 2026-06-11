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

int isKaibun(string &s){
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

	int A, B;
	cin >> A >> B;

	int ans = 0;
	for(int i=A; i<=B; i++){
		string s = to_string(i);
		if(isKaibun(s)){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
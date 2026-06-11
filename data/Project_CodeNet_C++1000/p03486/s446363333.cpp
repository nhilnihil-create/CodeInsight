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

	string s, t;
	cin >> s;
	cin >> t;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	std::reverse(t.begin(), t.end());
	int ret = strcmp(s.c_str(), t.c_str());
	if(ret < 0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
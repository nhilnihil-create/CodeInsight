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

	vector<LL> v;
	for(int i=0; i<3; i++){
		LL u;
		cin >> u;
		v.push_back(u);
	}
	sort(v.begin(), v.end());

	LL ans = 10*v[2] + v[1] + v[0];
	printf("%lld\n", ans);
	return 0;
}


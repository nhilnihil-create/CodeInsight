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

long long X, Y;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> X >> Y;

	long long ans = 1;
	long long v = X;
	while(true){
		v *= 2;
		if(v > Y){ break; }
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
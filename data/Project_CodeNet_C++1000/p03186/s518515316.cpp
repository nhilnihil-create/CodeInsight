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

	LL A, B, C;
	cin >> A >> B >> C;

	LL ans = 0;
	if(C <= A + B){
		ans = B + C;
	}
	else{
		ans = B + A + 1 + B;
	}
	printf("%lld\n", ans);
	return 0;
}
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

	LL N, A;
	cin >> N;
	cin >> A;

	LL r = N % 500;
	if(r <= A){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
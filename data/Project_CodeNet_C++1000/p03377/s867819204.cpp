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

	int A, B, X;
	cin >> A >> B >> X;
	if(X >= A && X <= (A+B)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
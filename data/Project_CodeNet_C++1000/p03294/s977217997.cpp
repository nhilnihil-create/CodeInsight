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

#define MAX 10000

// LCM(a[i])-1は、すべてのiに対して mod a[i] が a[i] -1 となる。
int main(int argc, char* argv[]){
	int N;
	cin >> N;

	long long ans = 0;
	for(int i=1; i<=N; i++){
		long long a;
		cin >> a;
		ans += (a - 1);
	}
	cout << ans << endl;
	return 0;
}
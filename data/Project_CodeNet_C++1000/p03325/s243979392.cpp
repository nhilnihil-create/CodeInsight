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

int a[MAX+2] = {0};

int main(int argc, char* argv[]){
	int N;
	cin >> N;

	long long ans = 0;
	for(int i=1; i<=N; i++){
		cin >> a[i];
		int b = a[i];
		int d = 0;
		while(true){
			if(b % 2 !=0) break;
			b = b / 2;
			d++;
		}
		ans += d;
	}
	cout << ans << endl;
	return 0;
}
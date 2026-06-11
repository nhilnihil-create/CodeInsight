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

int s[28] = {0};
int t[28] = {0};

int main(int argc, char* argv[]){
	int N, K;
	cin >> N >> K;

	long long ans = 0;
	//まずKの倍数をカウント
	long long kn = N / K;
	ans = kn * kn * kn;

	//Kが偶数の時は以下の組がある
	//a % K = K/2, b % K = K/2, c % K = K/2
	if(K % 2 == 0){
		long long count = 0;
		while(true){
			if(K*count + K/2 > N){
				break;
			}
			count++;
		}
		ans += (count * count * count);
	}

	printf("%lld\n", ans);
	return 0;
}
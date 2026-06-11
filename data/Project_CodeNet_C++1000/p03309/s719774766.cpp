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
	int N;
	vector<long long> A, a;

	cin >> N;
	for(int i=0; i<N; i++){
		long long v;
		cin >> v;
		A.push_back(v);
		a.push_back(v - (i + 1));
	}

	//ソートしておく
	sort(a.begin(), a.end());

	//bがb->b+1に変化するとき、悲しさは以下の通り変化する。
	// (b以下の個数) - (b+1以上の個数)
	// 全部でN個なので、(b以下の個数) - (N - b以下の個数)変化する。
	//　b以下の個数がN/2以下の場合は減り続け、b以下の個数がN/2を超えると増える。
	long long ans = 0, ans1 = 0, ans2=0, ans3=0;
	for(int i=0; i<N; i++){
		ans1 += abs(a[i] - a[N/2]);
	}
	for(int i=0; i<N; i++){
		ans2 += abs(a[i] - a[(N/2)]+1);
	}
	for(int i=0; i<N; i++){
		ans3 += abs(a[i] - a[(N/2)]-1);
	}
	ans = min(ans1, min(ans2, ans3));
	cout << ans << endl;
	return 0;
}
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

//b以上の最初の要素の位置を返す。ない場合は-1
//vはソート済であること。あと、&v でなくvだと引数コピーが発生するので遅い。
int lbound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] >= b){
			e = m;
		}
		else{
			s = m;
		}
	}
	if(v[max(s - 1, 0)] >= b) return max(s - 1, 0);
	else if(v[s] >= b) return s;
	else if(v[min(s + 1, l - 1)] >= b) return min(s + 1, l - 1);
	else return -1;
}

//bより大きいの最初の要素の位置を返す。ない場合は-1
//vはソート済であること。あと、&v でなくvだと引数コピーが発生するので遅い。
int ubound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] <= b){
			s = m;
		}
		else{
			e = m;
		}
	}
	if(v[max(s - 1, 0)] > b) return max(s - 1, 0);
	else if(v[s] > b) return s;
	else if(v[min(s + 1, l - 1)] > b) return min(s + 1, l - 1);
	else return -1;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long N;
	vector<long long> A, B, C;

	cin >> N;
	for(int i = 0; i < N; i++){
		long long v;
		cin >> v;
		A.push_back(v);
	}
	sort(A.begin(), A.end());

	for(int i = 0; i < N; i++){
		long long v;
		cin >> v;
		B.push_back(v);
	}
	sort(B.begin(), B.end());
	
	for(int i = 0; i < N; i++){
		long long v;
		cin >> v;
		C.push_back(v);
	}
	sort(C.begin(), C.end());

	//Bの要素bを軸に見る。
	//bについては {bより小さいAの要素の個数} *  {bより大きいCの要素の個数}で算出できる。
	long long ans = 0;
	for(int i = 0; i < N; i++){ //B.size() = N;
		long long numA = (long long) lbound(A, B[i]); //b以上の最初の要素の位置
		long long numC = (long long) ubound(C, B[i]); //bより大きい最初の要素の位置
		if(numA == 0 || numC == -1){
			continue;
		}
		if(numA == -1){
			numA = N;
		}
		ans += (numA * (N - numC)) ; //C.size() = N;
	}
	printf("%lld\n", ans);
	return 0;
}
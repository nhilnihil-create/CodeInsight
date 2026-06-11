#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;
int CC[200001];
set<int> Colors[200001];
ll Cases[200001];

// 処理後の石の列の0個目〜n個目までの場合の数
// メモ化再帰
ll CalcCases(int n){
	if(n == 0){
		return 1;
	}
	if(Cases[n] > 0){
		return Cases[n];
	}
	ll value = 0;
	value = CalcCases(n-1) % mod;
	auto lower = Colors[CC[n]].lower_bound(n);
	if(lower != Colors[CC[n]].begin()){
		auto p = prev(Colors[CC[n]].lower_bound(n));
		value += CalcCases(*p);
		value %= mod;
	}
	Cases[n] = value;
	return value;
}

int main()
{
	int N;
	cin >> N;
	int C[200001];
	for(int i = 0; i < N; i++){
		cin >> C[i];
	}
	fill(Cases, Cases+N, 0);
	
	// 同じ色が連続している場所は、１つの石とみなしてもよい
	int before = 0;
	int count = 0;
	for(int i = 0; i < N; i++){
		if(before != C[i]){
			CC[count] = C[i];
			count++;
		}
		before = C[i];
	}
	
	// 各色の場所を記憶
	for(int i = 0; i < count; i++){
		Colors[CC[i]].insert(i);
	}
	
	cout << CalcCases(count-1) << endl;
	
	return 0;
}
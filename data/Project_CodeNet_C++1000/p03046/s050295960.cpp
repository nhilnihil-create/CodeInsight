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

ll NthPowerOf2(ll N){
	ll ans = 1;
	for(int i = 0; i < N; i++){
		ans *= 2;
	}
	return ans;
}

int main()
{
	ll N, K;
	cin >> N >> K;
	
	// N = 1 の場合だけ特別
	if(N == 1){
		if(K == 0){
			cout << "0 0 1 1" << endl;
		}else{
			cout << -1 << endl;
		}
		return 0;
	}
	
	// N >= 2 のとき、0〜2^N-1 で各ビットについて、1が偶数回出てくることを利用する
	if(K >= NthPowerOf2(N)){
		cout << -1 << endl;
		return 0;
	}
	
	cout << K << " ";
	ll Max = NthPowerOf2(N);
	for(int i = 0; i < Max; i++){
		if(i != K){
			cout << i << " ";
		}
	}
	cout << K << " ";
	for(int i = Max-1; i >= 0; i--){
		if(i != K){
			cout << i << " ";
		}
	}
	cout << endl;
	
	return 0;
}
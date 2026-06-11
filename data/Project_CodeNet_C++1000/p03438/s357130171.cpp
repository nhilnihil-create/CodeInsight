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

using namespace std;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	ll a[10000];
	ll b[10000];
	ll aSum = 0;
	ll bSum = 0;
	for(int i = 0; i < N; i++){
		cin >> a[i];
		aSum += a[i];
	}
	for(int i = 0; i < N; i++){
		cin >> b[i];
		bSum += b[i];
	}
	
	ll opeCount = bSum - aSum;
	if(opeCount < 0){
		cout << "No" << endl;
		return 0;
	}
	
	ll evenOpe = opeCount;
	ll oddOpe = opeCount;
	
	for(int i = 0; i < N; i++){
		if(a[i] < b[i]){
			evenOpe -= (b[i] - a[i] + 1) / 2;
			oddOpe -= (b[i] - a[i]) % 2;
		}
		else if(b[i] < a[i]){
			oddOpe -= (a[i] - b[i]);
		}
	}
	
	if( evenOpe >= 0 && oddOpe >= 0 && oddOpe == evenOpe * 2){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	return 0;
}

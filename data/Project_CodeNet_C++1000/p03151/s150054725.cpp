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
	ll A[100000];
	ll B[100000];
	
	ll ASum = 0;
	ll BSum = 0;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		ASum += A[i];
	}
	for(int i = 0; i < N; i++){
		cin >> B[i];
		BSum += B[i];
	}
	
	if(BSum > ASum){
		cout << -1 << endl;
		return 0;
	}
	else if(BSum == ASum){
		cout << 0 << endl;
		return 0;
	}
	
	ll Diff[100000];
	for(int i = 0; i < N; i++){
		Diff[i] = A[i] - B[i];
	}
	
	ll remain = ASum - BSum;
	sort(Diff, Diff+N);
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(Diff[i] >= 0 && Diff[i] <= remain){
			remain -= Diff[i];
		}else{
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

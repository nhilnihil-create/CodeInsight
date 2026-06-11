#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int& i : arr) cin >> i;
	int DP[n];
	DP[n-1] = 0;
	for(int i = n-2; i >=0; --i){
		int mincost = INT_MAX;
		for(int j = i+1; j <= i+k && j < n; ++j){
			mincost = min(mincost, abs(arr[i] - arr[j]) + DP[j]);
		}
		DP[i] = mincost;
	}
	cout << DP[0] << endl;	
}
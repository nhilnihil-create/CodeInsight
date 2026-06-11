#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int& i : arr) cin >> i;
	int DP[n];
	DP[n-1] = 0;
	for(int i = n-2; i >=0; --i){
		DP[i] = DP[i+1] + abs(arr[i] - arr[i+1]);
		if(i+2 < n) DP[i] = min(DP[i], DP[i+2] + abs(arr[i] - arr[i+2]));
	}
	cout << DP[0] << endl;	
}
#include <bits/stdc++.h>
using namespace std;

void test(vector<int> &a, int k){
	bool dp[k+1];
	memset(dp, 0, sizeof(dp));
	int n = a.size();
	for(int j = 1; j <= k; j++){
		for(int i = 0; i < a.size(); i++){
			if(j >= a[i]){
				dp[j] = dp[j] || !dp[j-a[i]];
			}
		}
	}
	if(dp[k]) cout << "First" << endl;
	else cout << "Second" << endl;
	return;
}
 
int main(){ //no changes here
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i =0 ; i < n; i++){
		cin >> a[i];
	}
	test(a, k);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;


int main(){
	int n, k;
 	cin >> n >> k;
 	vector<int> choices(n, 0);
	for(int i = 0; i < n; i++){
		cin >> choices[i];
 	}
 	vector<bool> dp(k+1, false);
 	for(int i = 1; i < k + 1; i++){
		for(int j = 0; j < n; j++){
			if(i - choices[j] >= 0){
				dp[i] = dp[i] || !(dp[i-choices[j]]);
			}
		}
	}
 	if(dp[k])
		cout << "First" << endl;
    else
		cout << "Second" << endl;
	return 0;
}

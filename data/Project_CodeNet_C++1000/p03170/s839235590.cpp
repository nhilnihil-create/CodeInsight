#include <bits/stdc++.h>
using namespace std;

void test(vector<int> &a, int k){
	bool dp[k+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i < k + 1; i++){
		bool temp = 0;
		for(int j = 0; j < a.size(); j++){
			if(a[j]<=i){
				temp = temp||(!(dp[i-a[j]]));
			}
		}
		dp[i] = temp;
	}
	if(dp[k]){
		cout << "First";
	}
	else{
		cout << "Second";
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/input.txt", "r", stdin);
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i =0 ; i < n; i++){
		cin >> a[i];
	}
	test(a, k);
	return 0;
}
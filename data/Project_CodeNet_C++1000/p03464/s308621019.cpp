#include <bits/stdc++.h>

using namespace std;

void die() { cout << -1; exit(0); }

int main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	
	long long arr[n];
	for(int i = 0;i < n;i++) cin >> arr[n-1-i];
	
	long long low = 2, high = 4;
	if(arr[0] != 2) die();
	
	for(int i = 1;i < n;i++){
		if(low % arr[i] != 0) low = arr[i] + low - (low % arr[i]);
		else low = low - (low % arr[i]);
		
		if(high % arr[i] != 0) high = high - (high % arr[i]) + arr[i];
		else high = high - (high % arr[i]);
		//cout << low << " " << high << "\n";
		
		if(low >= high) die();
	}
	
	cout << low << " " << high-1 << "\n";
}

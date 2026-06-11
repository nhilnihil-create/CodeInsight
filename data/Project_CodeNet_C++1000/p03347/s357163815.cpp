#include<bits/stdc++.h>
using namespace std;

int arr[200003] , N;

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	if(arr[1] != 0){puts("-1"); return 0;}
	long long ans = 0; int pos = 1;
	for(int i = 2 ; i <= N ; ++i){
		if(arr[i] > i - pos){puts("-1"); return 0;}
		ans += arr[i] == arr[i - 1] + 1 ? 1 : arr[i];
		pos = max(pos , i - arr[i]);
	}
	cout << ans; return 0;
}
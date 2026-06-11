#include<iostream>

using namespace std;

int powerOfTwo(int n){
	int res = 0;
	while(n%2==0){
		n = n/2;
		res++;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		ans += powerOfTwo(a[i]);
	}
	cout << ans;
	
	return 0;
}
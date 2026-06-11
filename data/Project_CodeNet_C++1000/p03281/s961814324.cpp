#include<iostream>

using namespace std;

int countDivisors(int n){
	int count = 0;
	for(int i=1; i<=n; i++){
		if(n%i==0) count++;
	}
	return count;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	for(int i=1; i<=n; i+=2){
		if(countDivisors(i)==8) ans++;
	}
	cout << ans;
	return 0;
}
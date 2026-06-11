#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[5];
	int mod10;
	int mod10max = -1;
	int ans = 0;
	for(int i=0; i<5; i++){
		cin >> a[i];
		if(a[i]%10==0) mod10 = 0;
		else mod10 = 10-(a[i]%10);
		mod10max = max(mod10, mod10max);
		ans += a[i] + mod10;
	}
	cout << ans-mod10max;
	return 0;
}
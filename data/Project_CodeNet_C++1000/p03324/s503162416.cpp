#include<iostream>
#include<cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d,n;
	cin >> d >> n;
	long long ans = 0;
	int p = 1; for(int i=0; i<d; i++) p*= 100;
	if(n<=99) ans = n*p;
	else ans = 101*p;
	cout << ans;
	return 0;
}
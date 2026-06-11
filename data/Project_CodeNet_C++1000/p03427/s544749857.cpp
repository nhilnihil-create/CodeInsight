#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, ans, sum, fac = 1;

int main() {
	cin>>n;
	while(sum*10 + 9 <= n) {
		ans += 9;
		sum = sum*10 + 9;
		fac *= 10;
	}	
	for(int i = 9; i; i--)
		if(i*fac + sum <= n) {
			ans += i;
			break;
		}
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int solve(int n){
	int ans = 0;

	do{
		ans += (n%10);
		n /= 10;
	}while(n);

	return ans == 1 ? 10 : ans;
}

int main(){
	int n;

	cin>>n;

	auto ans = solve(n);

	cout<<ans<<'\n';

	return 0;
}
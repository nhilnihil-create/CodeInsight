#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;

int sumdig(int n){

	int ret = 0;

	while(n){
		ret+=n%10;
		n/=10;
	}

	return ret;

}

int main(){

	int n;

	cin >> n;

	int ans = INF;

	for(int i=1;i<n;++i){
		ans = min(ans,sumdig(i)+sumdig(n-i));
	}

	cout << ans << '\n';

	return 0;
}
// C - Strange Bank
#include <bits/stdc++.h>
using namespace std;

int f(int yen, int coin, int cnt=0){
	while(yen > 0){ cnt += yen % coin; yen /= coin; }
	return cnt;
}

int main(){
	int n; cin>>n;
	int ans = n;
	for(int yen6=0; yen6<=n; ++yen6)
		ans = min(ans, f(n-yen6, 9, f(yen6, 6)));
	cout<< ans <<endl;
}

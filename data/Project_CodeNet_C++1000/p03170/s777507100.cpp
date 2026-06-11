#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	vector<int> a(N);
	for(int i=0; i<N; i++) cin >> a[i];

	vector<bool> dp(K+1,false);
	for(int i=1; i<=K; i++){
		for(int j=0; j<N; j++){
			if( i-a[j]>=0 && !dp[i-a[j]]) dp[i] = true;
		}
	}

	if(dp[K]) cout << "First" << endl;
	else cout << "Second" << endl;

	return 0;
}


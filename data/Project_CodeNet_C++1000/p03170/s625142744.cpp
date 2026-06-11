#include<bits/stdc++.h>
using namespace std;
int dp[100000+5];
int A[100+5];

int main(int argc, char const *argv[])
{
	int N, K;
	while(cin >> N >> K) {
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<N; i++) {
			cin >> A[i];
		}
		for(int i=A[0]; i<=K; i++) {
			for(int j=0; j<N; j++) {
				if(i >= A[j] && dp[i - A[j]] == 0){
					dp[i] = 1;
					break;
				}
				else {
					dp[i] = 0;
				}
			}
		}
		if(dp[K]) {
			cout << "First" << endl;
		} else {
			cout << "Second" << endl;
		}
	}
	return 0;
}
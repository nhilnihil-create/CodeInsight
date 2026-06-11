#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <stack>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int DP[310][310][310] = {};

int main(){
	
	string S;
	int K;
	
	cin >> S;
	cin >> K;
	
	for(int i = 0; i < S.size(); i++){
		for(int j = S.size() - 1; j > i; j--){
			int id1 = i + 1;
			int id2 = S.size() - j;
			for(int k = 0; k <= K; k++){
				DP[id1][id2][k] = max(DP[id1 - 1][id2][k], DP[id1][id2 - 1][k]);
				if(k != 0){
					DP[id1][id2][k] = max(DP[id1][id2][k], DP[id1][id2][k - 1]);
				}
				if(S[i] == S[j]){
					DP[id1][id2][k] = max(DP[id1][id2][k], DP[id1 - 1][id2 - 1][k] + 1);
				}else if(k != 0){
					DP[id1][id2][k] = max(DP[id1][id2][k], DP[id1 - 1][id2 - 1][k - 1] + 1);
				}
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i <= S.size(); i++){
		ans = max(ans, DP[i][S.size() - i][K] * 2);
	}
	
	for(int i = 0; i < S.size(); i++){
		ans = max(ans, DP[i][S.size() - i - 1][K] * 2 + 1);
	}
	
	cout << ans << endl;
	
	return 0;
}

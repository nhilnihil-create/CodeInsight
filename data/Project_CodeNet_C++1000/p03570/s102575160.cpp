#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 200005;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const int doise26 = 1 << 26;
int prefixSum[SIZE];
int dp[doise26];
int minpos[SIZE];

int main() {
	string s;
	cin >> s;
	for(int i = 1; i <= s.length(); i++) {
		prefixSum[i] = prefixSum[i-1] ^ 1 << s[i-1] - 'a';
	}
	minpos[0] = INF;
	minpos[s.length() + 1] = 0;
	dp[0] = s.length() + 1;
	for(int i = 1; i <= s.length(); i++) {
		minpos[i] = minpos[dp[prefixSum[i]]] + 1;
		for(int j = 0; j < 26; j++) {
			minpos[i] = min(minpos[i], 1 + minpos[dp[prefixSum[i] ^ 1 << j]]);
		}
		if(minpos[dp[prefixSum[i]]] > minpos[i]) {
			dp[prefixSum[i]] = i;
		}
	}
	//for(int i = 1; i <= s.length(); i++) {
	//	printf("%d ", minpos[i]);
	//}
	//printf("\n");
	printf("%d\n", minpos[s.length()]);	
	return 0;
}
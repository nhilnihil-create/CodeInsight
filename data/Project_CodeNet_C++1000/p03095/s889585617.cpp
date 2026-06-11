#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

char s[MAXN];
int n, c[26];

int main(){
	scanf("%d %s", &n, s);
	
	for(int i = 0; i < n; i++){
		c[s[i] - 'a']++;
	}
	
	long long res = 1;
	for(int i = 0; i < 26; i++)
		res = res * (c[i] + 1) % MOD;
	printf("%lld\n", (res - 1 + MOD) % MOD);
	
	return 0;
}

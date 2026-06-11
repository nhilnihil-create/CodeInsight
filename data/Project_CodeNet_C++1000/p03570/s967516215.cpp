#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 50;
char a[maxn];
int f[maxn], sum[1 << 26];
int main(){
	scanf("%s", a + 1); int n = strlen(a + 1);
	memset(sum, 0x3f, sizeof(sum));
	int g = 0;
	f[0] = 0; sum[0] = 0;
	for (int i = 1; i <= n; ++i){
		int x = 1 << (a[i] - 'a');
		g ^= x;
		f[i] = sum[g];
		for (int j = 0; j < 26; ++j) f[i] = min(sum[g ^ (1 << j)], f[i]);
		++ f[i];
		sum[g] = min(sum[g], f[i]);
	}
	cout << f[n] << endl;
	return 0;
}
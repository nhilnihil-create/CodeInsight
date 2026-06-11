#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

const int N = 200010;
const int mod = 1e9 + 7;

inline int read() {
	int jg = 0, jk = getchar() - '0', f = 1;
	while(jk < 0 || jk > 9) {
	    if(jk == '-' - '0')  f = -1;
		jk = getchar() - '0';
	}
	while(jk >= 0 && jk <= 9)
		jg *= 10, jg += jk, jk = getchar() - '0';
	return jg * f;
}

int n, c, la[N], f[N], sum[N];
 
int main() {
	//freopen("a.txt", "r", stdin);
    n = read();
	f[0] = sum[0] = 1;
	for(int i = 1, j; i <= n; ++i) {
		j = read();
		if(!la[j]) {
			f[i] = 0;
			sum[i] = sum[i - 1] + f[i];
			la[j] = i;
			continue;
		}
		if(la[j] == i - 1) {
			la[j] = i;
			sum[i] = sum[i - 1];
			continue;
		}
		f[i] = sum[la[j]];
		if(f[i] >= mod)  f[i] -= mod;
		sum[i] = sum[i - 1] + f[i];
		if(sum[i] >= mod) sum[i] -= mod;
		la[j] = i;
		//cout<<i<<" "<<f[i]<<" "<<sum[i]<<endl;
	}
	printf("%d\n", sum[n]);
    return 0;
}
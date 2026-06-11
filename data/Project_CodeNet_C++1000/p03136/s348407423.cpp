#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

const int N = 60;
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

int n, mx, sum;
 
int main() {
	//freopen("a.txt", "r", stdin);
    n = read();
	for(int i = 1, l; i <= n; ++i) {
		l = read();
		sum += l;
		mx = max(mx, l);
	}
	if(sum > 2 * mx)  printf("Yes");
	else  printf("No");
    return 0;
}
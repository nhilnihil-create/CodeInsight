#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

#define inf 0x3f3f3f3f

#define lc k << 1
#define rc k << 1 | 1

using namespace std;

typedef long long ll;

char ch[200005];
int n;

int f[1 << 26];
int g[200005];
int main(){
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	memset(f, 0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	
	f[0] = 0; int ff = 0;
	for(int i = 1; i <= n; i ++){
		int t = ch[i] - 'a';
		ff = ff ^ (1 << t);
		if(ff == 0) g[i] = 1;
		for(int j = 0; j < 26; j ++){
			int r = ff ^ (1 << j);
			g[i] = min(g[i], f[r] + 1);
		}
		f[ff] = min(f[ff], g[i]); 
	}
	printf("%d\n", g[n]);
    return 0;
}
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#define ms(i, j) memset(i, j, sizeof i)
#define LL long long
#define db double
#define fir first
#define sec second
#define mp make_pair
using namespace std;

namespace flyinthesky {

	LL H, W, n, x, y, preS[4][200000 + 5], preT[4][200000 + 5], gg[4];
	char s[200000 + 5], t[200000 + 5];
	
    void clean() {
    }
    int solve() {
    	
    	clean();
    	cin >> H >> W >> n >> x >> y;
    	scanf("%s%s", s + 1, t + 1);
    	
    	gg[0] = H - x + 1;
    	gg[1] = x;
    	gg[2] = y;
    	gg[3] = W - y + 1;
    	
    	for (LL i = 1; i <= n; ++i) {
    		for (LL j = 0; j < 4; ++j) preS[j][i] = preS[j][i - 1], preT[j][i] = preT[j][i - 1];
    		if (s[i] == 'D') ++preS[0][i];
    		if (s[i] == 'U') ++preS[1][i];
    		if (s[i] == 'L') ++preS[2][i];
    		if (s[i] == 'R') ++preS[3][i];
    		
			if (t[i] == 'D') ++preT[0][i];
    		if (t[i] == 'U') ++preT[1][i];
    		if (t[i] == 'L') ++preT[2][i];
    		if (t[i] == 'R') ++preT[3][i];
    		
    		for (LL j = 0; j < 4; ++j) if (preT[j][i] - preS[j ^ 1][i] >= gg[j]) preT[j][i]--;
		}
		
		for (LL i = 1; i <= n; ++i) {
			for (LL j = 0; j < 4; ++j) {
				if (preS[j][i] - preT[j ^ 1][i - 1] >= gg[j]) return printf("NO\n"), 0;
			}
		}
    	printf("YES\n");
    	
        return 0;
    } 
}
int main() {
    flyinthesky::solve();
    return 0;
}
/*
*/
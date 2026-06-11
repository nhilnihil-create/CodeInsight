#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

int n;
char s[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);
	
	int res = 0;
	for(int x = 0; x < n; x++){
		bool ok = true;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if(s[i][j] != s[(j + x) % n][(i - x + n) % n]){
				ok = false;
			}
		}
		if(ok)res += n;
	}
	printf("%d\n", res);
	
    return 0;
}

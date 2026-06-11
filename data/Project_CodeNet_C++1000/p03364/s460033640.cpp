#include<bits/stdc++.h>
using namespace std;
const int maxn = 600 + 10;

int n;
char s[maxn][maxn];

int main() {
//	freopen("data.in","r",stdin);
  scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			s[i][j + n] = s[i][j];
			s[i + n][j] = s[i][j];
			s[i + n][j + n] = s[i][j];
		}
	}
	int cnt = 0, Ans = 0;
	for(int del = - n + 1;del <= n - 1;del ++) {
		int flag = 0; cnt = 0;
    for(int y = max(1,- del + 1);y <= n && del + y <= n;y ++) {
			int x = del + y;
      if(!flag) {
				for(int i = 1;i <= n;i ++) {
					for(int j = 1;j < i;j ++) {
            if(s[x + i - 1][y + j - 1] != s[x + j - 1][y + i - 1]) cnt ++;
					}
				}
				flag = 1;
			}
			else {
        for(int i = 1;i <= n;i ++) {
					if(s[x - 1][y - 1 + i - 1] != s[x - 1 + i - 1][y - 1]) cnt --;
				}
				for(int i = 1;i <= n;i ++) {
					if(s[x + i - 1][y + n - 1] != s[x + n - 1][y + i - 1]) cnt ++;
				}
			}
			if(!cnt) Ans ++;
		}
	}
	printf("%d\n", Ans);
	return 0;
}

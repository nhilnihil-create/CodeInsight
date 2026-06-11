#include<bits/stdc++.h>
using namespace std;

int n;
char s[100005];

int main() {
	scanf(" %s",s+1);
	n = strlen(s+1);
	if(s[1] == '0' || s[n] == '1') return !printf("-1");
	for(int i = 1; i <= n-1; i++) {
		if(s[i] != s[n-i]) return !printf("-1");
	}
	for(int x = 1, y = 1; x <= n; x++) {
		if(s[x] == '1' || x == n) {
			while(y<x) {
				printf("%d %d\n",y,x);
				y++;
			}
		}
	}
}
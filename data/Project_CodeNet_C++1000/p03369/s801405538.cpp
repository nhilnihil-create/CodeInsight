#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ans = 700;
char s[10];
int main(){
	scanf("%s", s + 1);
	for(int i = 1; i <= 3; ++i) ans += 100 * (s[i] == 'o');
	printf("%d\n", ans);
	return 0;
}
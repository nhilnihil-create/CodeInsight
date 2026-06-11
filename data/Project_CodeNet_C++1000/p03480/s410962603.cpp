#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100010;
char ch[N];
int ans = 0x3f3f3f3f;
int main() {
	cin >> ch + 1;
	int len = strlen(ch + 1);
	for(int i = 1; i <= len; i++) 
		if(ch[i] != ch[i + 1])
			ans = min(ans, max(i, len - i));
	printf("%d\n", ans);
	return 0;
}
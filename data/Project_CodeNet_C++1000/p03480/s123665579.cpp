#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
char s[N];
int len,ans;
int main(){
	scanf("%s",s+1);
	len = strlen(s+1);
	ans = len;
	for (int i = 2; i <= len; ++i)
		if (s[i] != s[i-1])  ans = min(ans, max(i-1, len - i + 1));
	printf("%d\n",ans);
	return 0;
}
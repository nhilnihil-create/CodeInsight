#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n; char s[N];
int main() {
	scanf("%s",s+1);
	int c=0;n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='o')c++;
	}
	c+=15-n;
	printf("%s\n", c>=8?"YES":"NO");
}
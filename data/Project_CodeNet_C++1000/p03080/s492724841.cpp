#include <bits/stdc++.h>
using namespace std;
const int N=102;
int n; char s[N];
int main() {
	scanf("%d%s",&n,s+1);
	int x=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='R')x++;
	}
	printf("%s\n", 2*x>n?"Yes":"No");
}
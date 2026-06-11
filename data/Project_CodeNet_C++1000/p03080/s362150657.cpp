#include<bits/stdc++.h>
using namespace std;
char s[120];
int n,ans;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='R')ans++;
		else ans--;
	}
	if(ans>0)printf("Yes\n");
	else printf("No\n");
}
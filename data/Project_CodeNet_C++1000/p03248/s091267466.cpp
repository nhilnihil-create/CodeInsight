#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<n;i++)
		if (s[i]!=s[n-i]){
			puts("-1");
			return 0;
		}
	if (s[1]=='0'||s[n]=='1'){
		puts("-1");
		return 0;
	}
	int last=n,now=1;
	for (int i=n-1;i;i--)
		if (s[i]=='1'){
			int k=last-i-1,p=now;
			while (k--){
				p++;
				printf("%d %d\n",now,p);
			}
			p++;
			printf("%d %d\n",now,p);
			last=i;now=p;
		}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
char s[maxn];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=n,num=0;
	for(int i=1;i<=n;i++){
		if((s[i]=='1'&&num%2==0)||(s[i]=='0'&&num%2==1)){
			int tmp=0;
			if(i-1>=n-i+1){
				tmp=i-1;
			}
			else {
				tmp=n-i+1;
				num++;
			}
			ans=min(ans,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}
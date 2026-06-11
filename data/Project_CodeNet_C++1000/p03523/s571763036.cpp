#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int>pii;
int n;
char s[100010];
const char t[100010]="\0AKIHABARA";
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int i,j;
	for(i=1,j=1;i<=n&&j<=9;){
		if(s[i]==t[j])i++,j++;
		else if(t[j]=='A')j++;
		else{
			puts("NO");
			return 0;
		}
	}
	for(;j<=9;j++)if(t[j]!='A'){
		puts("NO");
		return 0;
	}
	if(i==n+1&&j==10)puts("YES");
	else puts("NO");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
char s[210],t[210];
int n;
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	rep(i,n+1,2*n){
		s[i]=s[i-n];
	}
	bool flag=0;
	rep(i,0,n-1){
		int tmp=1;
		rep(j,1,n){
			if(t[j]!=s[i+j]){
				tmp=0;
				break;
			}
		}
		if(tmp){
			flag=1;break;
		}
	}
	if(flag)	puts("Yes");
	else	puts("No");
	return 0;
}

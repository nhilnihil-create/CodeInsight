#include<bits/stdc++.h>
using namespace std;
#define MN 100005
typedef long long ll;
int T,n,cnt;char ch[MN];
int main(){
//	freopen("test.in","r",stdin);
//	freopen("mysol.out","w",stdout);
	scanf("%s",ch+1);n=strlen(ch+1);bool pd=(ch[1]=='1')&(ch[n]=='0');
	for(int i=1;i<n;i++)pd&=(ch[i]==ch[n-i]);
	if(!pd)puts("-1");
	else {
		int lst=0,lstx=0;
		for(int i=1;i<=n/2;i++)if(ch[i]=='1'){
			int tmp=++cnt;if(lstx)printf("%d %d\n",tmp,lstx);
			for(int j=1;j<i-lst;j++)printf("%d %d\n",(++cnt),tmp);
			lst=i,lstx=tmp;
		}
		int tmp=++cnt;if(lstx)printf("%d %d\n",tmp,lstx);
		for(int j=1;j<n-lst;j++)printf("%d %d\n",(++cnt),tmp);
	}
}


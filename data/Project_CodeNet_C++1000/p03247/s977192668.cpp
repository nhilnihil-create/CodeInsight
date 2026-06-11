#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,cnt=0;
int x[N],y[N],m,X,Y,cmp;
char step[35]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i],&y[i]);
		if((x[i]+y[i])&1)cnt++;
		else cnt--;
	}
	if(abs(cnt)!=n){cout<<-1<<endl;return 0;}
	m=31+(cnt<0);
	printf("%d\n",m);
	for(int i=0;i<=30;i++)printf("%d ",1<<i);
	if(cnt<0)cout<<1;
	cout<<endl;
	for(int i=1;i<=n;i++){
		X=x[i];Y=y[i];cmp=0;
		if(cnt<0)step[31]='R',X--;
		for(int j=30;j>=0;j--){
			if(abs(X)<abs(Y))swap(X,Y),cmp^=1;
			if(X>0)X-=1<<j,step[j]=cmp?'U':'R';
			else X+=1<<j,step[j]=cmp?'D':'L';
		}
		printf("%s\n",step);
	}
	return 0;
}
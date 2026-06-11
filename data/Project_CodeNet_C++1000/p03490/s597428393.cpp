#include<bits/stdc++.h>
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=16035;
char s[16005];
int n,ex,ey,q[2][N];
bool visx[2][N],visy[2][N];
#define fx(i,j) visx[i][j+8000]
#define fy(i,j) visy[i][j+8000]
int main()
{
	scanf("%s%d%d",s+1,&ex,&ey); n=strlen(s+1);
	int now=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='T') break;
		ex--;now=i;
	}
	fx(0,0)=fy(0,0)=1;
	now++;
//	cout<<now<<endl;
	int k=1;
	for(int i=now+1,j;i<=n;i++){
		int cnt=0;
		for(j=i;j<=n;j++){
//			cout<<"gg "<<j<<' ';
			if(s[j]=='T') break;
			cnt++;
		}
//		cout<<' '<<i<<' '<<j<<' '<<cnt<<endl;
		if(k&1){
			for(int j=-8000;j<=8000;j++)
			  if(fy(0,j))
				fy(1,j+cnt)=fy(1,j-cnt)=1;//cout<<"goy "<<j-cnt<<' '<<j+cnt<<' ';
			memcpy(visy[0],visy[1],sizeof(visy[0]));
			memset(visy[1],0,sizeof(visy[1]));
//			for(int j=-10;j<=10;j++) cout<<fy(0,j)<<' '; cout<<endl;
		}
		else{
			 for(int j=-8000;j<=8000;j++)
			  if(fx(0,j))
				fx(1,j+cnt)=fx(1,j-cnt)=1;//cout<<"gox "<<j<<' ';
			memcpy(visx[0],visx[1],sizeof(visx[0]));
			memset(visx[1],0,sizeof(visx[1]));
//			for(int j=-10;j<=10;j++) cout<<fx(0,j)<<' '; cout<<endl;
		}
		i=j; k^=1;
	}
	if(fx(0,ex)&&fy(0,ey)) puts("Yes");
	else puts("No");
	return 0;
}
#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,i,x[1005],y[1005],flag;
void gz(long long u,long long v,long long w){
	if(w<0)
		return;
	if(abs(u)>abs(v)){
		if(u>0){
			putchar('R');
			gz(u-(1LL<<w),v,w-1);
		}
		else{
			putchar('L');
			gz(u+(1LL<<w),v,w-1);
		}
	}
	else{
		if(v>0){
			putchar('U');
			gz(u,v-(1LL<<w),w-1);
		}
		else{
			putchar('D');
			gz(u,v+(1LL<<w),w-1);
		}
	}
	if(w==0)
		putchar('\n');
}
int main(){
	n=read();
	for(i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		if((x[i]+y[i])&1)
			flag|=1;
		else
			flag|=2;
	}
	if(flag==3){
		pus(-1,2);
		return 0;
	}
	if(flag==2){
		pus(37,2);
		pus(1,1);
		for(i=35;i>=0;i--)
			pus(1LL<<i,1);
		cout<<endl;
		for(i=1;i<=n;i++){
			putchar('L');
			gz(x[i]+1,y[i],35);
		}
	}
	else{
		pus(36,2);
		for(i=35;i>=0;i--)
			pus(1LL<<i,1);
		cout<<endl;
		for(i=1;i<=n;i++)
			gz(x[i],y[i],35);
	}
    return 0;
}
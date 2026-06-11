#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l,m=0,a[62][3],tot=0,n=1,x=1;
inline void add(int aa,int b,int c){
	a[++m][0]=aa;
	a[m][1]=b;
	a[m][2]=c;
	return ;
}
int main(){
    scanf("%d",&l);
    l--;
    for(int i=1;i<20&&l;i++,x<<=1){
        if(x>l) break;
        add(i,i+1,x),add(i,i+1,0);
        l-=x;
		tot+=x;
		n=i+1;
    }
    if(l){
        for(int i=n;i;i--){
            if(1<<(i-1)<=l){
                l-=(1<<(i-1));
                add(i,n,tot+1);
                tot+=(1<<(i-1));
            }
        }
    }
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++) printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    return 0;
}
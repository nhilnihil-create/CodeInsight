#include<bits/stdc++.h>
int A,B,n,x,y;
char c[200010],s[200010];
bool chk(int X,int x,char A,char D){
	int L=1,R=X;
	for(int i=n;i>=1;i--){		
		L-=s[i]==A;R+=s[i]==D;
		if(L<1)L=1;if(R>X)R=X;
		R-=c[i]==A;L+=c[i]==D;
		if(L>R)return 1;
		if(R>X)R=X;if(L<1)L=1;
	} 
	return(L>x||R<x);
}
int main(){
	std::cin>>A>>B>>n>>x>>y;
	scanf("%s%s",c+1,s+1);
	puts((chk(A,x,'D','U')|chk(B,y,'R','L'))?"NO":"YES");
	return 0;
}

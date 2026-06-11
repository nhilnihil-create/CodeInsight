#include<iostream>
#include<cmath>
using namespace std;
long long n,h,w,a,b,ans;
int read(){
	int x=0,f=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-')
		f=-1;
	}while(ch>'9'||ch<'0');
	do{
		x=x*10+ch-'0';
		ch=getchar();
	}while(ch<='9'&&ch>='0');
	return f*x;
}
int main(){
	n=read();
	h=read();
	w=read();
	ans=0;
	for (int i=0;i<n;i++){
		a=read();
		b=read();
		ans+=min((a/h),(b/w));
	}
	cout<<ans<<endl;
	return 0;
}
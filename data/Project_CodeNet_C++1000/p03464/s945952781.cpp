#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll k,an1=2,an2=2,a[100005];
int main(){
	k=read();
	for(int i=0;i<k;i++)
		a[i]=read();
	if(a[k-1]!=2)return puts("-1"),0;
	for(int i=k-1;i;i--){
		an2=((an2+a[i]-1)/a[i-1])*a[i-1];
		an1=((an1+a[i-1]-1)/a[i-1])*a[i-1];
		if(an1>an2)return puts("-1"),0;
	}
	an2+=a[0]-1;
	cout << an1 << " " << an2;
	return 0;
}
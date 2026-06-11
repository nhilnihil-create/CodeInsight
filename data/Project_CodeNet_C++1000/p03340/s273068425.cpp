//Date:
#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	register int x;register char c(getchar());register bool k;
	//while((c<'0'||c>'9')&&c^'-')if((c=getchar())==EOF)exit(0);
	if(c^'-')x=c-'0',k=1;else x=0,k=0;
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return k?x:((~x)+1);
}
long long n;
long long num=0;
long long sum=0;
long long sums=0;
long long a[200200];
long long ans=0;
int main(){
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((sum^a[i])!=(sums+a[i])){
			while((sum^a[i])!=(sums+a[i])){
				sum^=a[i-num];
				sums-=a[i-num];
				ans+=num;
				num--;
			}
		}
		num++,sum=(sum^a[i]),sums=(sums+a[i]);
	}
	ans+=(num+1)*num/2;
	cout<<ans;
	return 0;
}
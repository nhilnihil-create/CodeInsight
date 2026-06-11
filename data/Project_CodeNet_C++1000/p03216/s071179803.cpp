#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (!isdigit(ch)){if (ch=='-')fh=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x=x*fh;
}
int n,q,k;
char ch[1000010];
int main(){
	read(n);
	for (int i=1;i<=n;i++){ch[i]=getchar();while (ch[i]<'A'||ch[i]>'Z')ch[i]=getchar();}
	read(q);
	while (q--){
		read(k);
		int nb=0,na=0;ll ans=0,nab=0;
		for (int i=1;i<=n;i++){
			if (i>k){
				if (ch[i-k]=='D'){na--;nab-=nb;}
				if (ch[i-k]=='M'){nb--;}
			}
			if (ch[i]=='D')na++;
			if (ch[i]=='M'){nab+=na;nb++;}
			if (ch[i]=='C')ans+=nab;
		}
		cout<<ans<<endl;
	}
	return 0;
}
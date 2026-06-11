#include<bits/stdc++.h>
#define rint register int
using namespace std;
inline int read(){
	char ch;
	while(!isdigit(ch=getchar()));
	int s=ch-'0';
	while (isdigit(ch=getchar()))s=s*10+ch-'0';
	return s;
}
const int N=4e6+5;
int n,ans;
bitset<N>s1,s2;
int main(){
	n=read();s1=1;
	for (rint i=1;i<=n;i++){
		int x=read();
		ans+=x;
		s2=s1;
		s1<<=x;
		s1|=s2;
	}
	for (rint i=ans/2+ans%2;i<=ans;i++)
		if (s1[i]){cout<<i;return 0;}
	return 0;
}



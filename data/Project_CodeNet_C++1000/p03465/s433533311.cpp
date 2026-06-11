#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t> inline void write(t x){
	if(x<0){putchar('-'),write(-x);}
	else{if(x>9)write(x/10);putchar('0'+x%10);}
}

int n;
bitset<4000005> s;

signed main(){
	read(n);
	s=1;
	while(n--){
		int x;
		read(x);
		s|=s<<x;
	}
	n=s.count()/2;
	for(int i=1;;i++) if(s[i]){
		if(--n==0){
			write(i);
			return 0;
		}
	}
}
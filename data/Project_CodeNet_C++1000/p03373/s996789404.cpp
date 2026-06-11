#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
typedef long long lint;

namespace utils{
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
	template <class T> inline void apn(T &x,const T y){x=x<y?x:y;}
	template <class T> inline void apx(T &x,const T y){x=x>y?x:y;}
	inline int nxi(){
		int x=0;
		char c;
		while(((c=getchar())>'9'||c<'0')&&c!='-');
		const bool f=c=='-'&&(c=getchar());
		while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
		return f?-x:x;
	}
}
using namespace utils;

int main(){
	int a=nxi(),b=nxi(),c=nxi(),x=nxi(),y=nxi();
	int n=std::min(x,y);
	if(a+b<=2*c){
		printf("%d\n",a*x+b*y);
	}else{
		printf("%d\n",n*c*2+(x-n)*std::min(a,c*2)+(y-n)*std::min(b,c*2));
	}
	return 0;
}

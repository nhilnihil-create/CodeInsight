#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
int t,n,k;
ll sx,sy,sz,sq;
string s;
int main(){
	in(n);
	cin>>s;
	in(t);
	int len=s.size();
	while(t--){
		in(k);
		int x=0,y=0;
		sx=sy=sz=sq=0;
		while(x<k){
			if(s[x]=='D')sx++;
			if(s[x]=='M')sy++,sz+=sx*1;
			if(s[x]=='C')sq+=sz*1;
			x++;
		}
		while(x<len){
			y=x-k;
			if(s[y]=='D')sx--,sz-=sy*1;
			if(s[y]=='M')sy--;
			if(s[x]=='D')sx++;
			if(s[x]=='M')sy++,sz+=sx*1;
			if(s[x]=='C')sq+=sz*1;
			x++;
		}
		printf("%lld\n",sq);
	}
	return 0;
}
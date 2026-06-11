#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<climits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;
#define ll long long
inline ll read() {
    char ch = getchar(); ll x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int main(){
//	freopen("03.txt","r",stdin);
	int n=read();
	for (int i=1;i<=n;i++)
	{
		ll x=read();
		ll y=read();
		if (x!=y)
		{ 
		ll p,o=sqrt((ll)(x)*y-1);
		if (o*o>(x*y-1)) o--;
		if (o*(o+1)<(x*y))
			p=o*2-1;
		else
		p=o*2-2;
		printf("%lld\n",p);
		}
		else
			printf("%lld\n",2*x-2);
	}
}
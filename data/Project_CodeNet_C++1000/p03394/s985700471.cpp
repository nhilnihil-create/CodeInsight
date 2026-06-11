//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,x,y,a[20005],m;
int main(){
	cin>>n;
	if(n==3)puts("2 5 63");
	else if(n==4)puts("2 5 20 63");
	else{
		while(1){
			++y;
			if(y%4==1||y%4==2) continue;
			x=0;
			for(int i=15;i>=0;--i){
				int X=x+(1<<i);
				if(X+y-min(X*2,y*3)/6<n)x=X;
			}
			++x;
			if(x<=15000&&x%3!=1) break;
		}
		for(int i=1;i<=x;++i)a[++m]=i*2;
		for(int i=1;i<=y;++i)if(i*3>x*2||(i&1))a[++m]=i*3;
		for(int i=1;i<n;++i)printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
    return 0;
}

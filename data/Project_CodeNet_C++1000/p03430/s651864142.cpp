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
string s,t;
int n,k,f[305][305][305],ans;
int main(){
	cin>>s;
	n=s.size();
	cin>>k;
	s=" "+s;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=k;++j)f[j][i][i]=1;
	}
	for(int d=1;d<n;++d){
		for(int r=d+1;r<=n;++r){
			int l=r-d;
			f[0][l][r]=max(f[0][l+1][r],f[0][l][r-1]);
			if(s[l]==s[r])f[0][l][r]=max(f[0][l][r],f[0][l+1][r-1]+2);
		}
	}
	ans=f[0][1][n];
	for(int _=1;_<=k;++_){
		for(int d=1;d<n;++d){
			for(int r=d+1;r<=n;++r){
				int l=r-d;
				f[_][l][r]=max(f[_][l+1][r],f[_][l][r-1]);
				if(s[l]==s[r])f[_][l][r]=max(f[_][l][r],f[_][l+1][r-1]+2);
				else f[_][l][r]=max(f[_][l][r],f[_-1][l+1][r-1]+2);
			}
		}
		ans=max(ans,f[_][1][n]);
	}
	printf("%d\n",ans);
    return 0;
}

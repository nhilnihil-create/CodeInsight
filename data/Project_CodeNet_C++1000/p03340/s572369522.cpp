// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define LL long long
#define ULL unsigned long long
#define DD double
using namespace std;
inline int read(){
    int red=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') red=(red<<3)+(red<<1)+ch-'0',ch=getchar();
    return red*f;
}
const int maxn=200005;
int n,A[maxn];
bool vis[35];
LL Ans;
int main(){
    n=read();
    for (int i=1;i<=n;i++) A[i]=read();
    int j=1;
    for (int bas=0;bas<=20;bas++) if (A[j]&(1<<bas)) vis[bas]=true;
    for (int i=1;i<=n;i++){
    	for (int bas=0;bas<=20;bas++) if (A[i-1]&(1<<bas)) vis[bas]=false;
		bool flg=true;
		while (flg&&j<n){
			for (int bas=0;bas<=20;bas++) if ((A[j+1]&(1<<bas))&&vis[bas]){flg=false;break;}
			if (flg){
				++j;
				for (int bas=0;bas<=20;bas++) if (A[j]&(1<<bas)) vis[bas]=true;
			}
		}
		Ans=Ans+j-i+1; 
	}
	cout<<Ans;
	return 0;
}
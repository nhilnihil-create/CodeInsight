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
string s;
int main(){
	cin>>s;
	if(s.size()<26){
		for(char c='a';c<='z';++c){
			bool ok=1;
			for(int i=0;i<s.size();++i)if(s[i]==c)ok=0;
			if(ok==1){
				s+=c;
				break;
			}
		}
		cout<<s<<endl;
		return 0;
	}
	int k=25;
	while(k&&s[k]<s[k-1])--k;
	if(!k)puts("-1");
	else{
		int I=0;
		for(int i=k;i<=25;++i)if(s[i]>s[k-1]&&(I==0||s[i]<s[I]))I=i;
		swap(s[k-1],s[I]);
		for(int i=0;i<k;++i)cout<<s[i];
		cout<<endl;
	}
    return 0;
}

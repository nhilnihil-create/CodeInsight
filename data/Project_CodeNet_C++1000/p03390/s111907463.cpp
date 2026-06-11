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
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//作者:中国江苏南京丁天行
using namespace std;
int q;
ll A,B;
ll calc(ll k){
    if((k+A)%2ll==0) return ((A+k)/2ll)*((A+k)/2ll+1ll);
    return ((A+k+1ll)/2ll)*((A+k+1ll)/2ll);
}
int main(){
    cin>>q;
    while(q--){
        cin>>A>>B;
        if(A>B)swap(A,B);
        ll l=A,r=orz;
        while(r-l>1){
            ll m=(l+r)/2ll;
            if(calc(m)<A*B)l=m;
            else r=m;
        }
        l=min(l,B-1ll);
        if(calc(A)>=A*B)l=A-1;
        cout<<l+A-1ll<<endl;
    }
	//system("pause");
	return 0;
}

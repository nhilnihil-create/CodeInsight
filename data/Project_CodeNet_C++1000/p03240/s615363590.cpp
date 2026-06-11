#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <functional>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include<new>
#include <numeric>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
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
using namespace std;
int N;
struct ss{
    int x, y, h;
} a[101];
int num=0;
int cx, cy;
int main() {
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i].x>>a[i].y>>a[i].h;
    }
    for(cx=0;cx<101;cx++){
        for(cy=0;cy<101;cy++){
            num=0;
            bool check=true;
            int hig=0;
            for(int i=1;i<=N;i++){
                if(a[i].h>0) hig=max(abs(a[i].x-cx)+abs(a[i].y-cy)+a[i].h,0);
            }
            for(int i=1;i<=N;i++){
                if(a[i].h!=max(hig-(abs(a[i].x-cx)+abs(a[i].y-cy)),0)) check=false;
            }
            if(check&&hig!=0){
                cout<<cx<<" "<<cy<<" "<<hig<<endl;
                return 0;
            }
        }
    }
    cout<<num<<endl;
    return 0;
}
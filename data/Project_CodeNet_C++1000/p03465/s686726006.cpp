#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;
#define Rint register int
int qr(){Rint ret=0,f=1;register char ch = getchar();while(!isdigit(ch)) f=ch=='-'?-1:1,ch=getchar();while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();return ret * f;}

int N;
#define maxN 2000*2000+10
#ifndef maxN
#define maxN 50
#define debug
#endif // maxN
bitset <maxN> f;
int sum,target;

int main(){
    N = qr();
    f[0]=1;
    for(Rint i = 1,t;i<=N;++i){
        t = qr();
        #ifdef debug
        cout << "     f " << f << endl;
        cout << "  f<<t " << (f<<t) << endl;;
        #endif // debug
        f|=(f<<t);
        sum += t;
    }
    #ifdef debug
    cout << f;
    #endif // debug
    for(Rint i = (sum+1)/2;;i++){
        if(f[i]) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
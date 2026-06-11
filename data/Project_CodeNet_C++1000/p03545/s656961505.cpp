#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< string, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789


///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int X;
int A, B, C, D;

int main(){
    
    cin>>X;
    
    A = X/1000;
    B = (X/100)%10;
    C = (X/10)%10;
    D = X%10;
    
    if( A+B+C+D == 7 ){printf("%d+%d+%d+%d=7", A, B, C, D);}
    else if( A+B+C-D == 7 ){printf("%d+%d+%d-%d=7", A, B, C, D);}
    else if( A+B-C+D == 7 ){printf("%d+%d-%d+%d=7", A, B, C, D);}
    else if( A+B-C-D == 7 ){printf("%d+%d-%d-%d=7", A, B, C, D);}
    else if( A-B+C+D == 7 ){printf("%d-%d+%d+%d=7", A, B, C, D);}
    else if( A-B+C-D == 7 ){printf("%d-%d+%d-%d=7", A, B, C, D);}
    else if( A-B-C+D == 7 ){printf("%d-%d-%d+%d=7", A, B, C, D);}
    else if( A-B-C-D == 7 ){printf("%d-%d-%d-%d=7", A, B, C, D);}
    
    puts("");
    
    return 0;
}

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

int C[3][3];
bool ans = true;

int main(){
    
    REP( i, 3 ) REP( j, 3 ) cin>>C[i][j];
    
    REP( i, 2 ){
        if( C[i+1][0]-C[i][0] != C[i+1][1]-C[i][1] || C[i+1][2]-C[i][2] != C[i+1][1]-C[i][1] ) ans = false;
    }
    
    if( ans ){
        puts("Yes");
    }
    else{
        puts("No");
    }
    
    return 0;
}

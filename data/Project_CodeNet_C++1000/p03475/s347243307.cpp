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

int N;
int C[512];
int S[512];
int F[512];


int main(){
    
    
    cin>>N;
    REP( i, N-1 ) cin>>C[i]>>S[i]>>F[i];
    
    REP( i, N ){
        int t = 0;
        FOR( j, i, N-1 ){
            if( t < S[j] ) t = S[j]+C[j];
            else{
                if( t % F[j] == 0 ) t += C[j];
                else{
                    t += C[j]+(F[j]-(t%F[j]));
                }
            }
        }
        cout<<t<<endl;
    }
    
    return 0;
}

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
string S[112345];
ll cnt[5];
ll ans = 0;

int main(){
    
    fill( cnt, cnt+5, 0 );
    
    cin>>N;
    REP( i, N ) cin>>S[i];
    
    REP( i, N ){
        if( S[i][0] == 'M' ){
            cnt[0]++;
        }
        if( S[i][0] == 'A' ){
            cnt[1]++;
        }
        if( S[i][0] == 'R' ){
            cnt[2]++;
        }
        if( S[i][0] == 'C' ){
            cnt[3]++;
        }
        if( S[i][0] == 'H' ){
            cnt[4]++;
        }
    }
    
    REP( i, 5 ){
        FOR( j, i+1, 5 ){
            FOR( k, j+1, 5 ){
                ans += cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}

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
int F[100][10];
ll P[100][11];
int cnt[10];
ll ans = -mod*mod;
ll sum;


int main(){
    
    cin>>N;
    REP( i, N ){
        REP( j, 10 ){
            cin>>F[i][j];
        }
    }
    
    REP( i, N ){
        REP( j, 11 ){
            cin>>P[i][j];
        }
    }
    
    int s = 1<<10;
    
    while( s > 1 ){
        s--;
        sum = 0;
        REP( i, N ) cnt[i] = 0;
        REP( i, N ){
            REP( j, 10 ){
                if( s&(1<<j) && F[i][j] ) cnt[i]++;
            }
        }
        REP( i, N ) sum += P[i][cnt[i]];
        ans = max( ans, sum );
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}

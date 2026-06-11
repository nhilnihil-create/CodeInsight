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
typedef pair< ll, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000003;
//              123456789


///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int N;


ll clc( ll y, ll m ){
    ll a = y;
    ll res = 1;
    while( m ){
        if( m % 2 ) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        res /= 2;
    }
    return res;
}

int main(){
    
    cin>>N;
        
    cout<<180*(N-2)<<endl;
    
    
    return 0;
}


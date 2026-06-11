#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <numeric>
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
const ll mod = 1000000007;
//              123456789

 
///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int ans;
int N;
int idx;
string S;

int sum;
int dp[1<<26];

int main(){
	
	cin>>S;
	N = S.size();

	fill( dp, dp+(1<<26), mod );
	
	dp[0] = 0;
	
	REP( i, N ){
		idx = S[i]-'a';
		sum ^= (1<<idx);
		
		REP( j, 26 ){
			dp[sum] = min( dp[sum], dp[sum^(1<<j)]+1 );
		}
	}
	
	cout<<max( 1, dp[sum] )<<endl;
	
	return 0;

}
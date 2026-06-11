//Coded by not_surrender
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

#define MAXN 300003
#define MOD 1000000007
#define oo (1<<20)
#define mid ((a+b)/2)
#define pb push_back
#define sz size()
#define fastCpp() ios_base::sync_with_stdio( false ), cin.tie( NULL ), cout.tie( NULL )

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;

struct Data{
	int n1, n2;
	Data(int n1 = 0, int n2 = 0):n1(n1),n2(n2){}
}dp[MAXN];

int N, M, ans;
 
int main(){

    #ifndef ONLINE_JUDGE
		//~ freopen( "a.txt", "r", stdin );
    #endif // ONLINE_JUDGE
    
    fastCpp();
    
    scanf( "%d", &N );
    
    M = (1<<N);
    
    for ( int i = 0; i < M; ++i )
		scanf( "%d", &dp[i].n1 );
    
    for ( int i = N-1; i >= 0; --i ){
		for ( int j = M-1, nxt; j > 0; --j ){
			nxt = j-(j&(1<<i));
			if ( nxt < j ){
				if ( dp[nxt].n1 > dp[j].n1 )
					dp[j].n2 = dp[j].n1, dp[j].n1 = dp[nxt].n1;
				else
					dp[j].n2 = max( dp[j].n2, dp[nxt].n1 );
			}
		}
	}
	
	for ( int i = 1, ans = 0; i < M; ++i ){
		ans = max( ans, dp[i].n1+dp[i].n2 );
		printf( "%d\n", ans );
	}
	
return 0;
}

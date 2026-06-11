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

int N, A[MAXN], ans, best[2];
 
int main(){

    #ifndef ONLINE_JUDGE
		//~ freopen( "a.txt", "r", stdin );
    #endif // ONLINE_JUDGE
    
    fastCpp();
    
    scanf( "%d", &N );
    
    N = 1<<N;
    
    for ( int i = 0; i < N; ++i )
		scanf( "%d", &A[i] );
		
	for ( int i = 1; i < N; ++i ){
		best[0] = A[0];
		best[1] = 0;
		for ( int j = i; j; j = (j-1)&i )
			if ( A[j] > best[0] )
				best[1] = best[0], best[0] = A[j];
			else
				if ( A[j] > best[1] )
					best[1] = A[j];
		ans = max( ans, best[0]+best[1] );
		printf( "%d\n", ans );
	}
	
return 0;
}

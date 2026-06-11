#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define fi first 
#define se second 
const int maxn = 2e5 + 100 ;
set < pair < int , int  > > s ;
ll a[maxn] , n, r , l , mid  ;
void add ( int i ) 
{
	if ( s.rbegin()->se!= 0) 
		s.insert ( { a[i-1] + 1 , 0 } ) ;
}
bool check( int x ) 
{
	s.clear() ;
	s.insert ( { 0 , 0 } ) ;
	for ( int i = 1 ; i<n ; i++)
	{
		if ( a[i] > a[i-1] ) 
			add ( i ) ;
		else
		{
			
			while ( s.rbegin()->fi > a[i] ) 
				s.erase( *s.rbegin() ) ;
			if ( s.rbegin()->se != x ) 	
			{	
				int col = s.rbegin()->se ;
				if ( s.rbegin()->fi == a[i]  ) 
					s.erase ( *s.rbegin() ) ;
				if ( s.empty() || (!s.empty() && s.rbegin()->se!=col+1))
					s.insert ( { a[i] , col+1 } ) ;
			}
			else
			{
				int ind = s.rbegin()->fi ;
				if ( ind == 0 )
					return false ;
				s.erase( *s.rbegin() ) ;
				int col = s.rbegin()->se ;
				if ( s.rbegin()->fi == ind-1 ) 
					s.erase ( *s.rbegin() ) ;
				if ( s.empty() || (!s.empty() && s.rbegin()->se != col + 1 ) ) 
					s.insert ( { ind-1 , col+ 1 } ) ;
				s.insert ( {ind , 0 } ) ;			
			}
		}
	}
	return true ;
}
void bs()
{
	l = -1 , r = n+1 ;
	while ( r-l > 1 ) 
	{
		 mid = ( l+r) /2 ;
		if ( check ( mid ) ) 
			r = mid ;
		else
			l = mid ;
	}
	cout << r+1 << endl;
}
int main()
{
	 cin >> n ;
	 for ( int i = 0 ;i<n ; i++)
		 cin >> a[i] , a[i] -- ;
	bs() ; 
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
ll s[ 41 ];
int a[ N ];
int n , cnt;
bool vis[ N ];
map< int , int > t;
int check1( int x ){//二分寻找第一个比他大的2次幂 
   int l = 0 , r = 32;
   while( l < r ){
   	int mid = ( l + r )/2;
   	if( s[ mid ] > x ) r = mid  ;else
   	l = mid + 1 ;
   }
   return l;
}
int check2( int j , int x ){
	int l = 1 ,  r = j;
    while( l < r ){
     int mid = ( l + r )/2;
     if( a[ mid ] == x  ) return mid;
     if( a[ mid ] > x ) r = mid;else
	 l = mid + 1; 
	}
	if( a[ l ] != x ) return -1;
	return l ;
}
int main( ){
//	freopen("powers.in" , "r" , stdin );
//	freopen("powers.out" , "w" , stdout );
    memset( vis , false , sizeof( vis ) );
	scanf("%d" , &n );
	s[ 0 ] = 1;
	for( int i = 1 ; i <= 32 ; i ++ ) s[ i ] = s[ i - 1 ] * 2; 
	for( int i = 1 ; i <= n ; i ++ ){
	 scanf("%d" , &a[ i ] );
	 t[ a[ i ] ] ++;
    }
	sort( a + 1  , a + n + 1 );
    for( int i = n ; i >= 1 ; i -- ){
	 int q = check1( a[ i ] );
     int p = check2( i , s[ q ] - a[ i ] );
//     cout<<p<<" "<<i<<" "<<q<<" "<<a[ i ]<<" "<<t[ a[ i ] ]<<endl;
     if( t[ a[ p ] ] == 0 ) continue; 
     if( t[ a[ i ] ] == 0 ) continue;
	 if( p == -1 ) continue;
	 if( a[ p ] == a[ i ] ) if( t[ a[ p ] ] < 2 ) continue;
	 t[ a[ i ] ]--;
	 t[ a[ p ] ]--;
	 cnt ++;
	} 
	cout<<cnt;
} 
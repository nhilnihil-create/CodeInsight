#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
ll s[ 41 ];
int a[ N ];
int n , cnt;
map< int, int > e;
int check1( int x ){//二分寻找第一个比他大的2次幂 
   int l = 0 , r = 32;
   while( l < r ){
   	int mid = ( l + r )/2;
   	if( s[ mid ] > x ) r = mid  ;else
   	l = mid + 1 ;
   }
   return l;
}
int main( ){
//	freopen("powers.in" , "r" , stdin );
//	freopen("powers.out" , "w" , stdout );
	scanf("%d" , &n );
	s[ 0 ] = 1;
	for( int i = 1 ; i <= 32 ; i ++ ) s[ i ] = s[ i - 1 ] * 2; 
	for( int i = 1 ; i <= n ; i ++ ){
	 scanf("%d" , &a[ i ] );
	 e[ a[ i ] ]++;
    }
	sort( a + 1  , a + n + 1 );
    for( int i = n ; i >= 1 ; i -- ){
     if( e[ a[ i ] ] == 0 ) continue;
	 int p = check1( a[ i ] );
//	 cout<<p << " "<<i <<" "<<a[ i ]<<" "<<e[ a[ i  ]]<<endl;
	 int q = s[ p ] - a[ i ];
	 if( q == a[ i ] ){
	  if( e[ q ] >= 2 ){
	  	cnt ++;
	  	e[ q ] -= 2;
	  }
	 }else
	 if ( e[ q ] >= 1 ){
	 	cnt++;
	 	e[ q ]--;
	 	e[ a[ i ] ]--;
	 }
   }
	cout<<cnt;    
} 
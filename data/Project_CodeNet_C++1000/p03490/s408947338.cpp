#include <bits/stdc++.h>
using namespace std;
const int N = 8200;
const int MAX_VAL = 8000;

int n, to_x, to_y, dis_x, dis_y, sum_x, sum_y;
int x[N], y[N], tot_x = 0, tot_y = 0;
bool fx[N], fy[N];
string s;

int main()
{
	cin>> s; n = s.length();
	scanf( "%d%d", &to_x, &to_y );
	
	int now = 0;
	while( s[now] == 'F'&& now < n )
		now ++;
	dis_x = to_x - now; dis_y = to_y;
		
	int cur = 1, sum = 0; now++;
	// 0 : x, 1 : y
	while( now < n ) 
	{
		if( s[now] == 'F' ) {
			sum ++; now++; continue;
		}
		
		if( cur == 1 )
			y[++tot_y] = sum;
		else x[++tot_x] = sum;
		sum = 0; cur ^= 1; now++;
	}
	if( cur == 1 ) 
		y[++tot_y] = sum;
	else x[++tot_x] = sum;
	
	memset( fx, false, sizeof( fx ) );
	memset( fy, false, sizeof( fy ) );
	fx[0] = true; fy[0] = true;
	
	for( int i = 1; i <= tot_x; i ++ )
		for( int j = MAX_VAL; j >= x[i]; j -- )
			if( !fx[j] ) fx[j] = fx[j-x[i]]; 
	
	for( int i = 1; i <= tot_y; i ++ )
		for( int j = MAX_VAL; j >= y[i]; j -- )
			if( !fy[j] ) fy[j] = fy[j-y[i]];
			
	for( int i = 1; i <= tot_x; i ++ )
		sum_x += x[i];
	for( int i = 1; i <= tot_y; i ++ )
		sum_y += y[i];
		 
//	printf( "sum_x:%d, sum_y:%d\n", sum_x, sum_y );
//	printf( "dis_x:%d, dis_y:%d\n", dis_x, dis_y );
		 
	sum_x -= dis_x; sum_y -= dis_y;
	if( sum_x % 2 == 1 || sum_y % 2 == 1 ) {
		puts( "No" ); return 0;
	}
	
//	printf( "sum_x:%d, sum_y:%d\n", sum_x, sum_y );
	
	if( sum_x < 0 || sum_y < 0 ) {
		puts( "No" ); return 0;
	}
	
	sum_x /= 2; sum_y /= 2;
	if( !fx[sum_x] || !fy[sum_y] ) 
		puts( "No" ); 
	else puts( "Yes" );
		
	return 0;
}
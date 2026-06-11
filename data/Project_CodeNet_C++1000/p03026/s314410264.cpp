#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *next;
} pool[210000] , *g[120000];
int top;
int n;
int a[120000];
int c[120000] , index , ans;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
	}
	c[i] = a[++index];
}
void dfs2 ( int i , int from ) {
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		ans += min ( c[i] , c[j->v] );
		dfs2 ( j -> v , i );
	}
}
void work () {
	int i , u , v;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	dfs ( 1 , -1 );
	dfs2 ( 1 , -1 );
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d " , c[i] );
}
int main () {
	work ();
	return 0;
}

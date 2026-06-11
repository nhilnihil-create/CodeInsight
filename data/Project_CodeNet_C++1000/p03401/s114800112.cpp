# include <bits/stdc++.h>
# define fi first
# define se second

using namespace std ;

long long N, vc[1000000] ;
long long sum, x;

int main() {
    cin >> N ;
    for( int i = 1 ; i <= N ; i ++ ) {
        cin >> vc[i] ;
        sum += abs(vc[i]-vc[i-1]) ;
    }
    sum += abs(vc[N]-0) ;
    for( int i = 1 ; i <= N ; i ++ ) {
        x = sum ;
        x -= abs( vc[i]-vc[i-1] ) ;
        x -= abs( vc[i]-vc[i+1] ) ;
        x += abs( vc[i-1] - vc[i+1] ) ;
        cout << x << endl;
    }
}

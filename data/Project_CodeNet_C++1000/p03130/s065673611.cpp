# include <bits/stdc++.h>
# define fi first
# define se second

using namespace std ;

int vc[4][2];
int us[4], cnt ;

int main() {
    for( int i = 1 ; i <= 3 ; i ++ ) {
        cin >> vc[i][1] >> vc[i][2] ;
        us[vc[i][1]] ++ ;
        us[vc[i][2]] ++ ;
    }
    for( int i = 1 ; i <= 4; i ++ ) {
        if( us[i] == 1 ) cnt ++ ;
    }
    if( cnt > 2 ) cout << "NO" << endl;
    else cout << "YES" << endl;
}

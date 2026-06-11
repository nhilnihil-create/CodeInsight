    # include <bits/stdc++.h>
    # define fi first
    # define se second

    using namespace std ;

    int vc[110][110], cnt=1, cnt2;
    int W, B,x ;

    int main() {
        cin >> W >> B ;
        if( W > B ) x = true ;
        else x = false ;

        for( int j = 1 ; j <= 100 ; j += 2 ) {
            for( int i = 1 ; i <= 100 ; i += 2 ) {
                if( x == true && cnt == W) break ;
                if( x == false && cnt == B ) break ;

                vc[i][j+1] = true ;
                vc[i+1][j+1] = true ;
                vc[i+1][j] = true ;
                cnt ++ ;
            }
        }
        if( cnt > 1 ) cnt2 = 1;
        for( int i = 2 ; i <= 99 ; i ++ ) {
            for( int j = 2 ; j <= 99 ; j ++ ) {
                if( x == true && cnt2 == B) break ;
                if( x == false && cnt2 == W ) break ;
                if( vc[i][j] == false ) {
                    if( vc[i][j+1] == false && vc[i][j-1] == false && vc[i+1][j] == false && vc[i-1][j] == false && vc[i+1][j+1] == false && vc[i+1][j-1] == false && vc[i-1][j+1] == false && vc[i-1][j-1] == false ) {
                        cnt2 ++ ;
                        vc[i][j] = true ;

                    }
                }
            }
        }
        cout << 100 << ' ' << 100 << endl;
        for( int i = 1 ; i <= 100 ; i ++ ) {
            for( int j = 1; j <= 100 ; j ++ ) {
                if( x == true ) {
                   if( vc[i][j] == true ) cout << '#' ;
                   else cout << '.' ;
                }
                else {
                    if( vc[i][j] == true ) cout << '.' ;
                    else cout << '#' ;
                }
            }
            cout << endl;
        }
    }

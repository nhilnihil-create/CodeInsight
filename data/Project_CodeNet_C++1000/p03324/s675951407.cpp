#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int d , n ;
    cin >> d >> n ;
    int A[3][100] ;
    int j = 0 ;
    int k = 0 ;
    int l = 0 ;
    for( int i = 1 ; i < 1e8 ; i++ ){
        if(i%100 != 0 && j < 100 ){
            A[0][j] = i ;
            j++ ;
        }
        if(i%100 == 0 && k < 100 ){
            if((i/100)%100 == 0 ){
                if(((i/100)/100)%100 == 0 ) continue ;
                A[2][k] = i ;
                k++ ;  
            }
            else{
                if( l < 100 ) A[1][l] = i ;
                l++ ;
            }
        }
    }
    cout << A[d][n-1] << endl;
}

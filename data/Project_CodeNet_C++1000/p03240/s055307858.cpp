#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ;i++)
int main(){
    int n ;cin >> n ;ll X[n] , Y[n] , H[n] ;
    rep(i,n) cin >> X[i] >> Y[i] >> H[i] ;
    int ans_H = 0 ,ans_Y = 0 ;
    ll ans_X = 0 ;
    ll ch ;  
    rep(x,101){
        rep(y,101){
            rep(i,n) if( H[i] != 0 ) ch =(ll) H[i] + abs(x - X[i]) + abs(y - Y[i]) ;
            int count = 0 ;
            rep(i,n) if( H[i] == max(ch - abs(x - X[i]) - abs(y - Y[i]),(ll)0) )count++ ;
            if( count == n ){
                    ans_H = ch ;
                    ans_X = x  ;
                    ans_Y = y  ;
            }
        }
    }
    cout << ans_X << " " << ans_Y << " " << ans_H << endl;
}
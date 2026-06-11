#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll a , b  ;
    cin >> a >> b ;
    vector<int> A(1001,0) ;
    rep(i,1000){
        A.at(i+1) = A.at(i) + (i+1) ;
        if(A.at(i+1) - A.at(i) == b - a ) cout << A.at(i) - a << endl;
    } 
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

ll ryuka ( ll N , vector<ll> &memo ){
    
    if( N == 0 ){
        return 2 ;
    }
    
    else if( N == 1 ){
        return 1 ;
    }
    
    if( memo.at(N) != -1 ){
        return memo.at(N) ;
    }
    
    else{
        memo.at(N) = ryuka ( N-1 , memo ) + ryuka ( N-2 , memo ) ;
        return memo.at(N) ;
    }
}

int main() {
    ll N ;
    cin >> N ;
    
    vector<ll> memo( N+1 , -1 ) ;
    
    cout << ryuka ( N , memo ) << endl;
}

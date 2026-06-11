#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> si( string s ){
    vector<char> A(s.size()) ;
    
    for( int i=0 ; i<s.size() ; i++ ){
        A.at(i) = s.at(i) ;
    }
    
    vector<ll> a(s.size()) ;
    for( int i=0 ; i<s.size() ; i++ ){
        a.at(i) = A.at(i) - '0' ;
    }
    
    return a ;
}

int main() {
    string S ;
    cin >> S ;
    
    for( int tmp=0 ; tmp< ( 1 << 4 ) ; tmp++ ){
        bitset<4> p(tmp) ;
        
        string K = S ;
        vector<ll> A = si(S) ;
        ll ans = 0 ;
        
        for( int i=0 ; i<4 ; i++ ){
            if( p.test(i) ){
                A.at(3-i) *= -1 ;
                K.insert( (3-i) , "-" ) ;
            }
            else{
                if( i != 3 ){
                    K.insert( (3-i) , "+" ) ;
                }
            }
            ans += A.at(3-i) ;
            
        }
        
        if( ans == 7 ){
            cout << K << "=7" << endl;
            break;
        }
        
    }
}

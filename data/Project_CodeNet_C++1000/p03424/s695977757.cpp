#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int n ;
    cin >> n ;
    map<string,int> mp ;
    rep(i,n){
        string s ;
        cin >> s ;
        mp[s]++ ;
    }
    int count = 0 ;
    for( auto p : mp ){
        count++ ;
    }
    if(count == 3 )cout << "Three" << endl ;
    if(count == 4 )cout << "Four" << endl ;
}
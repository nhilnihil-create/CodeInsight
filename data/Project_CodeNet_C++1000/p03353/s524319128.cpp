#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ;i++ )

int main(){
    string s ;
    cin >> s ;
    int n ;
    cin >> n ;
    set<string> T ;
    int k = s.size() ;
    rep(i,k){
        rep(j,6){
            T.insert(s.substr(i,j));
        }
    }
    int count = 0 ;
    for(auto p : T ){
        if( n == count)cout << p << endl ;
        count++ ;
    } 
}
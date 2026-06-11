#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>
#include<functional>
#include<set>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    string s ;
    cin >> s ;
    int a = 0 ;
    int b = 0 ;
    int c = 0 ;
    rep(i,3){
        if(s[i] == 'a' ) a++ ;
        if(s[i] == 'b' ) b++ ;
        if(s[i] == 'c' ) c++ ;
    }  
    if(a&&b&&c)cout << "Yes" <<endl;
    else cout << "No" << endl;
}
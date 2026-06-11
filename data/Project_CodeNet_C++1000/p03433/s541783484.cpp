#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int n , d ;
    cin >> n >> d ;
    if( n%500 <= d ){
        cout << "Yes" <<endl;
    }
    else{
        cout << "No" << endl;
    }
}
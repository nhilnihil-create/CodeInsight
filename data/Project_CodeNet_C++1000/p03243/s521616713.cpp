#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int N ;
    cin >> N ;
    for(int i = N ;; i++ ){
        if(i%10 == (i%100)/10 && (i%100)/10 == i/100 ){
            cout << i << endl;
            return 0 ;
        }
    }
}
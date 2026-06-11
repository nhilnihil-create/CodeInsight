#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int n , m , x , y ;
    cin >> n >> m >> x >> y ;
    int ans_x = -105 ;
    int ans_y =  105 ;
    rep(i,n){
        int a ;
        cin >> a ;
        ans_x = max(ans_x,a) ;
    } 
    rep(i,m){
        int b ;
        cin >> b ;
        ans_y = min(ans_y,b) ;
    } 
    for(int z = x+1 ;z <= y ;z++ ){
        if(z > ans_x && z <= ans_y ){
            cout << "No War" << endl;
            return 0 ;
        }
    }
    cout << "War" << endl;
}
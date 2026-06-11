#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int n , m , X , Y ;
    cin >> n >> m >> X >> Y ;

    int x[n] ;
    int y[m] ;
    for(int i =  0 ; i < n ; i++){
        cin >> x[i] ;
    }
    for(int j = 0 ; j < m ; j++){
        cin >> y[j] ;
    }

    sort(x , x+ n) ;
    sort(y , y + m ) ;
    
    bool flag = false ;
    
    if(X>=Y){
        flag = true ;
    }
    int now = x[n-1] +1;
    for(int k = 0 ; k < x[n-1] - y[0] ; k++ ){
         if(now <= X || now > Y){
            flag = true ;
         }
         now ++ ;
    }
    
     if(x[n-1] < y[0] && x[n-1] < Y && y[0] > X) cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}
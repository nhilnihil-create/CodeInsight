#include <bits/stdc++.h>
using namespace std;

int abslength(int a , int b);
int notabslength(int a , int b);

signed main(){
    int n , k , x[100005] , ans = 1000000000;

    cin >> n >> k;
    ans = 3 * 100000000;

    for(int i=0 ;i<n ;i++ ){
        cin >> x[i];
        if(k == 1){
            ans = min(ans , abs(x[i]));
        }
    }

    if(k > 1){
        for(int i=k-1 ;i<n ;i++ ){
            if( (x[i] > 0 && x[i-k+1] > 0) || (x[i] < 0 && x[i-k+1] < 0) ){
                ans = min(ans , notabslength(x[i] , x[i-k+1]));
            } else {
                ans = min(ans , abslength(x[i] , x[i-k+1]));
            }
        }
    }
    cout << ans << endl;

    return(0);
}

int notabslength(int a , int b){
    return( max(abs(a) , abs(b)) );
}

int abslength(int a , int b){
    return( min(a * 2 - b , a - b * 2) );
}
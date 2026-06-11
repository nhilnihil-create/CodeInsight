#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
typedef long long int ll;

int main(void){
    ll n , k ;
    cin >> n >> k ;

    ll a[k] ;
    ll ama =  n % k ;
    if(ama == 0){
        for(ll i = 0 ; i < k ; i++ ){
            a[i] = (n / k) ;
        }
    }else{
        for(ll i = 0 ; i < k ; i++ ){
            if(i < ama){
                a[i] = (n / k) + 1 ;
            }else{
                a[i] = (n / k) ;
            }
        }
    }

    ll ans = 0 ;
    if(k % 2 == 0){
        cout << a[k-1] * a[k-1] * a[k-1] + a[k/2 -1] * a[k/2 -1] * a[k/2 -1] << endl;
    }else{
        cout << a[k-1] * a[k-1] * a[k-1] << endl;
    }
   
    return 0;
}
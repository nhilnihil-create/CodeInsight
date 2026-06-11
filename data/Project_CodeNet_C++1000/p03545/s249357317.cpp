#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{   
    string s ;
    cin >> s ;
    ll a[4] ;
    for(ll i = 0 ; i < 4 ; i++){
        a[i] = s[i] - '0' ;
    }

    ll ans = 0 ;

    
        for(ll k = 0 ; k < 2 ; k++){
            for(ll l = 0 ; l < 2 ; l++){
                for(ll m = 0 ; m < 2 ;m++){
                    ans += a[0] ;
                    if(k == 0){
                        ans += a[1] ;
                    }else{
                        ans -= a[1] ;
                    }
                    if(l == 0){
                        ans += a[2] ;
                    }else{
                        ans -= a[2] ;
                    }
                    if(m == 0){
                        ans += a[3] ;
                    }else{
                        ans -= a[3] ;
                    }

                    if(ans == 7){
                        cout << a[0] ;
                        if(k==0){
                            cout << "+" ;
                        }else{
                            cout << "-" ;
                        }
                        cout << a[1] ;
                        if(l==0){
                            cout << "+" ;
                        }else{
                            cout << "-" ;
                        }
                        cout << a[2] ;
                        if(m==0){
                            cout << "+" ;
                        }else{
                            cout << "-" ;
                        }
                        cout << a[3] ;
                        cout << "=7" << endl;

                        return 0 ;
                    }
                    ans = 0 ;
                }
            }
        }
    

    
    

    return 0;
}
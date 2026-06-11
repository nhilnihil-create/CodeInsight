#include<bits/stdc++.h>
using namespace std ;

const int mod = 1e9 + 7 ; 

int n ;

int a[100010] ;

long long Pow(long long foo, long long bar){
    long long ans = 1ll ;
    while(bar){
        if(bar % 2) ans = (ans * foo) % mod ;
        foo = (foo * foo) % mod ;
        bar /= 2 ;
    }
    return ans ;
}

long long prefix[100010] ;

int main(){
    #define NAME "example"
    //freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

    ios_base :: sync_with_stdio(false) ;

    cin >> n ;

    for (int i = 1; i <= n; ++ i) cin >> a[i] ;

    for (int i = 1; i <= n; ++ i) prefix[i] = prefix[i - 1] + Pow(1ll * (i + 1), 1ll * (mod - 2)), prefix[i] %= mod ; 

    long long foo = 1 ;
    
    for (int i = 1; i <= n; ++ i) foo *= 1ll * i, foo %= mod ;

    long long ans = 0 ;
    
    for (int i = 1; i <= n; ++ i){
        long long bar = prefix[i - 1] + prefix[n - i] + 1ll ; bar %= mod ;
        ans += 1ll * bar * a[i] ; ans %= mod ;
    }

    cout << (ans * foo) % mod << endl ; 

    return 0 ;
}
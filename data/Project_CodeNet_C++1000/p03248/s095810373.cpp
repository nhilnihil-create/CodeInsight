#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std ;

const int N = 200010 ;

int n ;
int m ;
int top ;
int cnt ;
char s[N] ;
int sz[N] ;
int stk[N] ;

int main(){
    cin >> (s + 1) ;
    n = strlen(s + 1) ;
    if (s[1] == '0') return puts("-1"), 0 ;
    if (s[n] == '1') return puts("-1"), 0 ;
    for (int i = 1 ; i < n ; ++ i)
        if (s[i] != s[n - i]) return puts("-1"), 0 ;
    /*
    for (int i = 1 ; i < n ; ++ i)
        if (s[i] == '1') stk[++ top] = i ;
    stk[++ top] = n ; int k ; cnt = 0 ;
    while (top) sz[++ cnt] = stk[top --] ;
    for (int i = 1 ; i < cnt ; ++ i)
        printf("%d %d\n", i, i + 1), sz[i] -= sz[i + 1] ;
    k = cnt ;
    for (int i = 1 ; i <= cnt ; ++ i)
        for (int j = 1 ; j <= sz[i] ; ++ j)
            printf("%d %d\n", i, ++ cnt) ;
    */
    m = 1 ;
    for (int i = 1 ; i < n ; ++ i){
        cout << i + 1 << " " << m << endl ;
        if (s[i] == '1') m = i + 1 ;
    }
    return 0 ;
}
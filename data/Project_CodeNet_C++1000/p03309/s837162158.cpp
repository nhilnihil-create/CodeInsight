#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std ;

const int N = 300010 ;

int n, k[N] ;
int base[N] ;
long long s, ans ;

int main(){
    cin >> n ; int p ;
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", &base[i]), k[i] = base[i] - i ;
    sort(k + 1, k + n + 1) ;
    if (n & 1) p = k[n / 2 + 1] ;
    else p = (k[n / 2] + k[n / 2 + 1]) / 2 ;
    for (int i = 1 ; i <= n ; ++ i)
        ans += 1ll * abs(base[i] - p - i) ;
    cout << ans << endl ; return 0 ;
}

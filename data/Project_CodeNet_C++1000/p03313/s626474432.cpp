#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std ;
 
typedef long long ll ;
 
#define fr(i) f[i].first
#define sc(i) f[i].second
#define pint pair<int, int>
 
const int N = 300010 ;
 
ll ans ;
int m, n ;
pint f[N] ;
ll base[N] ;
 
bool comp(int x, int y){
    return base[x] > base[y] ;
}
int main(){
    cin >> m ; n = (1 << m) - 1 ;
    for (int i = 0 ; i <= n ; ++ i){
        cin >> base[i] ;
        f[i] = make_pair(i, n + 1) ;
    }
    base[n + 1] = -1 ;
    for (int i = 0 ; i <= n ; ++ i)
        for (int j = 0 ; j < m ; ++ j)
            if (!((1 << j) & i)){
                int k = (1 << j) | i ;
                int t[4] = {fr(i), sc(i), fr(k), sc(k)} ;
                sort(t, t + 4, comp) ; unique(t, t + 4) ;
                f[k] = make_pair(t[0], t[1]) ;
            }
    for (int i = 1 ; i <= n ; ++ i){
        ans = max(ans, base[fr(i)] + base[sc(i)]) ;
        cout << ans << endl ;
    }
}
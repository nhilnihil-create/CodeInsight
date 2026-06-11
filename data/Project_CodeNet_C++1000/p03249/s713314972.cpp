#include<bits/stdc++.h>
using namespace std ;

int n ;

pair < long long , int > d[100010] ;

int nChild[100010] ;

map < long long , int > f;

vector < pair < int , int > > lis ;

int main(){
    #define NAME "example"
    //freopen(NAME".inp", "r", stdin) ; freopen(NAME".out", "w", stdout) ;

    ios_base :: sync_with_stdio(false) ;

    cin >> n ;

    for (int i = 1; i <= n; ++ i) cin >> d[i].first, d[i].second = i ;

    sort(d + 1, d + n + 1) ;

    long long total = 0 ;

    for (int i = 1; i <= n; ++ i) f[d[i].first] = d[i].second ;
    for (int i = n; i >= 2; -- i){
        long long foo = d[i].first + 2ll * (nChild[d[i].second] + 1) - 1ll * n ;
        int bar = f[foo] ;
        if(!bar) return cout << -1 , 0 ;
        nChild[bar] += nChild[d[i].second] + 1 ;
        if(bar != d[1].second && 2 * nChild[bar] >= n) return cout << -1, 0 ;
        lis.push_back(make_pair(d[i].second, bar)) ;
        total += 1ll * (nChild[d[i].second] + 1) ;
    }
    if(total != d[1].first) return cout << -1, 0 ;

    for (int i = 0; i < (int)lis.size(); ++ i) cout << lis[i].first << " " << lis[i].second << endl ;

    return 0 ;
}

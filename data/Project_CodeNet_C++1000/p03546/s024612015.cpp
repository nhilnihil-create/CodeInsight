#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int h , w ;
    cin >> h >> w; 
    vector<vector<int>> c(10, vector<int> (10)) ;
    rep(i, 10){
        rep(j, 10){
            cin >> c[i][j] ;
        }
    }
    vector<vector<int>> tab (h, vector<int> (w)) ;
    rep(i, h){
        rep(j, w){
            cin >> tab[i][j] ;
        }
    }
    rep(k, 10){
        rep(i, 10){
            rep(j, 10){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]) ;
            }
        }
    }
    ll ans = 0 ;
    rep(i, h){
        rep(j, w){
            if(tab[i][j] != -1){
                int p = tab[i][j] ;
                ans += c[p][1] ;
            }
        }
    }
    cout << ans << endl ;
} 
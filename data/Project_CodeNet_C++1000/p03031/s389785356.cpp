#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
int main (){
    int n, m;
    cin >> n >> m ;
    vector<vector<int>> sw (m) ;
    vector<int> p (m) ;
    int ans = 0 ;
    rep(i, m){
        int k ;
        cin >> k ;
        rep(j, k){
            int s ;
            cin >> s; 
            sw[i].push_back(s) ;
        }
    }
    rep(i, m){
        cin >> p[i] ;
    }
    rep(i, 1 << n){
        bool can = true ;
        rep(j, m){
            int num = 0; 
            rep(k, sw[j].size()){
                if(i >> (sw[j][k] - 1) & 1){
                    num++ ;
                }
            }
            if(num % 2 != p[j]){
                can = false; 
                break ;
            }
        }  
        if(can){
            ans++ ;
        }      
    }
    cout << ans << endl ;
}

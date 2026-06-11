#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
using namespace std;
int main(void){
    ll N , K ;
    cin >> N >> K ;
    ll h[N] ;
    rep(i , N ){
        cin >> h[i] ;
    }
    ll ans = 1e9; ;
    ll tmp ;
    sort(h , h +N) ;
    rep(j , N - K + 1 ){
        tmp = h[j + K - 1] - h[j] ;
        if(ans > tmp){
            ans = tmp ;
        }
    }
    cout << ans << endl;
    return 0 ;
}
    
  
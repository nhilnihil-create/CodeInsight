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
int w2(int N ){
    ll ans = 0 ;
    while(N != 0){
    if(N %2 == 0){
        ans++ ;
        N = N / 2 ;
    }else{
        break ;
    }
    }
    return ans ;
}
int main()
{   
    ll N ;
    cin >>N ;
    int a ;
    int ans = 0 ;
    for(ll i = 0 ; i < N ; i++){
         cin >> a ;
         ans += w2(a) ;
    }
    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main(){
    int q ;
    int mx = 100005 ;
    cin >> q;
    vector<int> isprime (mx, 1) ;
    isprime[0] = 0 ;
    isprime[1] = 0 ;
    for(int i = 2; i < mx ; i++){
        if(isprime[i]){
            for(int j = 2*i ; j < mx ; j += i){
                isprime[j] = 0 ;
            }
        }
    }
    vector<int> like (mx) ;
    rep(i, mx){
        if(i % 2 == 0){
            continue ;
        }
        if(isprime[i] == 1 && isprime[(i + 1)/2] == 1){
            like[i] = 1 ;
        }
    }
    rep(i, mx){
        if(i == 0) continue ;
        else {
            like[i] += like[i - 1] ;
        }
    }
    vector<int> ans ;
    rep(i, q){
        int l, r ;
        cin >> l >> r ;
        if(like[l] != like[l - 1]){
            ans.push_back(like[r] - like[l] + 1) ;
        }
        else {
            ans.push_back(like[r] - like[l]) ;
        }
    }
    rep(i, q){
        cout << ans[i] << endl ;
    }
} 
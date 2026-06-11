#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 10000000000000000 

int main (){
    int n ;
    cin >> n ;
    vector<int> a (n) ;
    vector<int> b (n) ;
    vector<int> c (n) ;

    rep(i, n){
        cin >> a[i] ;
    }
    rep(i, n){
        cin >> b[i] ;
    }
    rep(i, n){
        cin >> c[i] ;
    }
    sort(a.begin(), a.end()) ;
    sort(b.begin(), b.end()) ;
    sort(c.rbegin(), c.rend()) ;
    ll ans = 0 ;
    rep(i, n){
        int k = b[i] ;
        ll lb = -1, ub = n  ;
        while (ub - lb > 1){
            int mid = (lb + ub)/2 ;
            if(c[mid] > k){
                lb = mid ;
            }
            else {
                ub = mid ;
            }
        }
        ll llb = -1, uub = n ;
        while(uub - llb > 1){
            int mid = (llb + uub) /2 ;
            if(a[mid] < k){
                llb = mid ;
            }
            else {
                uub = mid ;
            }
        }
        ans += (lb + 1) * (llb + 1) ;
    }      
    cout << ans << endl ;

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> a(n) ;
    ll sum = 0 ;
    rep(i,n){
        cin >> a[i] ;
        sum += a[i] ;
    } 
    sort(a.begin(),a.end()) ;
    cout << (k - sum)/a[0] + n <<endl;
}
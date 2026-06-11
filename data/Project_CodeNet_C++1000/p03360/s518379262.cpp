#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    vector<int> a(3) ;
    rep(i,3) cin >> a[i] ;
    int k ;
    cin >> k ;
    sort(a.begin(),a.end()) ;
    cout << a[0] + a[1] + a[2]*pow(2,k) <<endl;
}
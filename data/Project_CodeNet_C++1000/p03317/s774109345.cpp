#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;


int main() {

    int n,k;
    cin >> n >> k ;
    int a[n];
    int ans ;

    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }

    double tmp = n-k ;
    if(tmp==0){
     cout << 1 << endl ;
     return 0 ;
    }
    else{
     double tmp2 = tmp/(k-1) ;
     ans = ceil(tmp2) ;
    }

    cout << ans+1 << endl ;

    return 0 ;
}
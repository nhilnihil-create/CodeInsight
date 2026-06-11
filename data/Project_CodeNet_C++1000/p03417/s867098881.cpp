#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n,m; cin >> n >> m;
    long long ans;
    ans = 0;

    bool p,q,r;

    p = (n == 1);
    q = (m == 1);
    r = ((n == 2) || (m == 2));
    
    if(p && q){
    cout << 1 << endl;
    return 0;
    }

    if(p && !q){
    cout << m - 2 << endl;
    return 0;
    }

    if(!p && q){
    cout << n - 2 << endl;
    return 0;
    }

    if(r){
    cout << 0 << endl;
    return 0;
    }

    ans = ( n - 2 ) * ( m - 2 ); 

    cout << ans << endl;

}
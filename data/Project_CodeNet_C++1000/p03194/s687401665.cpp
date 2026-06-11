//
//  main.cpp
//  CPP
//
//  Created by chemistrae on 02/12/2018.
//  Copyright © 2018 chemistrae. All rights reserved.
//

#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll n,p;

ll pow(ll n, ll r) {
    if (r == 0) return 1;
    ll ret;
    if (r % 2) {
        ret = n*pow(n, r-1);
    }
    else {
        ll tmp = pow(n, r/2);
        ret = tmp*tmp;
    }
    if (ret > p)
        return 0;
    else
        return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> p;
    
    //cout << pow(2, 3) << '\n';
    
    if (n == 1) {
        cout << p << '\n';
        return 0;
    }
    
    ll r = 1, ret = 1;
    while (true) {
        ll e = pow(r, n);
        if (e == 0)
            break;
        if ((p % e) == 0)
            ret = max(ret, r);
        r++;
    }
    
    cout << ret << '\n';
    
    return 0;
}

#include <bits/stdc++.h>
#include<iostream>
#define LL long long
using namespace std;

LL gcd(LL a, LL b){
    LL x,y,z;
    if (a > b) { 
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }
    z = x % y;
    if (z == 0) {
        return y;
    } else {
        return gcd(y,z);
    }
}


int main(void)
{
    LL n,p;
    cin >> n >> p;
    if (n == 1) {
        cout << p << endl;
    } else {
        LL ma = pow(p, 1.0/n)+1;
        for (LL l = ma; l > 0; l--){
            LL lx = pow(l, n-1);
            if (p % lx != 0) continue;
            LL ly = p / lx;
            LL lz = gcd(ly,l);
            if (lz == l) {
                cout << l << endl;
                return 0;
            }
        }
    } 


    return 0;
}
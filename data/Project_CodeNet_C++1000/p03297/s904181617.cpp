#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
    if(b == 0) return a;
    else return GCD(b, a % b);
}

bool solve(long long a, long long b, long long c, long long d) {
    if(a < b) return false;
    if(d < b) return false;
    if(c >= b - 1) return true;

    long long g = GCD(b , d);
    long long m = b + a%g - g;
    if(m > c) return false;
    else return true;
}

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; ++i) {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        if(solve(a,b,c,d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    } 
}
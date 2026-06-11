#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(d < b){ cout << "No" << endl; continue; }
        if(a < b){ cout << "No" << endl; continue; }
        if(c >= b){ cout << "Yes" << endl; continue; }

        long long int x = gcd(b,d);
        long long int y = a % x + (b - x);
        if(y > c)  cout << "No"  << endl;
        if(y <= c) cout << "Yes" << endl;
    }
    return 0;
}
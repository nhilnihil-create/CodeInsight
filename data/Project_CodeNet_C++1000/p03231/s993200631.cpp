#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b) {
    return a / gcd(a,b) * b;// divide first to avoid overflow
}

int main(){
    long long int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    long long int l = lcm(n,m);
    long long int x = lcm(n/gcd(n,m), m/gcd(n,m));
    for(int i=0; i<l/x; i++){
        //cout << i*x/(l/n) << " " << i*x/(l/m) << endl;
        if(s[i*x/(l/n)] != t[i*x/(l/m)]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << l << endl;
    return 0;
}
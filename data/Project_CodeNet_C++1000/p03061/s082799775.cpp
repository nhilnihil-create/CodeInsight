#include <iostream>
using namespace std;

int gcd (int a,int b){
    while(b){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
/*
L(0) = 0
L(i + 1) = gcd(L(i), A(i))
R(N + 1) = 0
R(i) = gcd(R(i + 1), A(i))
*/
int n, a[100005], b[100005], c[100005], res;
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
      
    b[1] = a[1];
    for (int i = 2; i <= n; i++) b[i] = gcd(b[i-1], a[i]);
    c[n] = a[n];
    for (int i = n-1; i >= 1; i--) c[i] = gcd(c[i+1], a[i]);
    for (int i = 2; i < n; i++) res = max(gcd(b[i-1], c[i+1]), res);
    cout << max(res, max(c[2], b[n-1])) << endl;
    return 0;
}
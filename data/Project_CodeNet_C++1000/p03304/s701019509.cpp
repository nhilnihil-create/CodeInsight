#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n,m,d;
    cin >> n >> m>> d;
   
    long double ans = ((max(n-2*d,0LL)%n +n) *(m-1))/(long double)(n*n);
    cout << setprecision(10)<< ans << endl;

    return 0;
}
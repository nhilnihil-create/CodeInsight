#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll A, B; cin >> A >> B;
    ll a = A + B;
    ll b = A - B;
    ll c = A * B;
    ll maxv = max(a, b);
    maxv = max(maxv, c);
    cout << maxv << endl;
    




}
